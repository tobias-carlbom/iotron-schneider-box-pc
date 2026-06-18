# Convert raw disk image to VDI format without VBoxManage
# VDI 1.1 fixed-size image format

param(
    [string]$RawPath = (Join-Path $PSScriptRoot "grafikscan_cf.img"),
    [string]$VdiPath = (Join-Path $PSScriptRoot "grafikscan_cf.vdi")
)

$ErrorActionPreference = "Stop"

if (-not (Test-Path $RawPath)) {
    Write-Host "ERROR: Raw image not found: $RawPath" -ForegroundColor Red
    exit 1
}

if (Test-Path $VdiPath) {
    Write-Host "VDI already exists: $VdiPath" -ForegroundColor Yellow
    Write-Host "Delete it first if you want to re-convert." -ForegroundColor Yellow
    exit 0
}

$rawSize = (Get-Item $RawPath).Length
Write-Host "Raw image: $RawPath ($([math]::Round($rawSize / 1GB, 2)) GB)" -ForegroundColor Cyan

# VDI 1.1 fixed-size format
$headerSize = 400
$imageType = 2          # fixed
$blockSize = 1048576    # 1 MB
$blocksInHdd = [math]::Ceiling($rawSize / $blockSize)
$batEntries = $blocksInHdd
$batSize = $batEntries * 4
$preHeaderSize = 512

# Data offset: after pre-header + BAT, aligned to 512 bytes
$dataOffset = $preHeaderSize + $batSize
if ($dataOffset % 512 -ne 0) {
    $dataOffset = [math]::Ceiling($dataOffset / 512) * 512
}

# Geometry (CHS)
$sectors = 63
$heads = 16
$cylinders = [math]::Floor($rawSize / (512 * $sectors * $heads))
if ($cylinders -gt 16383) { $cylinders = 16383 }

# Generate UUIDs
$uuid1 = [guid]::NewGuid().ToByteArray()
$uuid2 = [guid]::NewGuid().ToByteArray()

Write-Host "Creating VDI header..." -ForegroundColor Cyan
Write-Host "  Disk size: $rawSize bytes"
Write-Host "  Blocks: $blocksInHdd x $($blockSize / 1KB) KB"
Write-Host "  BAT offset: $preHeaderSize"
Write-Host "  Data offset: $dataOffset"
Write-Host "  Geometry: C=$cylinders H=$heads S=$sectors"

# Build header (pre-header area is 512 bytes, header starts at offset 64)
$header = New-Object byte[] $preHeaderSize

# Signature text at offset 0
$sigText = [System.Text.Encoding]::ASCII.GetBytes("<<< Oracle VM VirtualBox Disk Image >>>`n")
[Array]::Copy($sigText, 0, $header, 0, $sigText.Length)

# Write values using BitConverter
function Write-UInt32($arr, $offset, $val) {
    $bytes = [BitConverter]::GetBytes([int32]$val)
    [Array]::Copy($bytes, 0, $arr, $offset, 4)
}
function Write-UInt64($arr, $offset, $val) {
    $bytes = [BitConverter]::GetBytes([long]$val)
    [Array]::Copy($bytes, 0, $arr, $offset, 8)
}

# Header fields (starting at offset 64)
# VDI signature 0xBEDA107F in little-endian
$header[64] = 0x7F; $header[65] = 0x10; $header[66] = 0xDA; $header[67] = 0xBE
# Version 1.1 = 0x00010001
$header[68] = 0x01; $header[69] = 0x00; $header[70] = 0x01; $header[71] = 0x00
Write-UInt32 $header 72  $headerSize     # header size (400)
Write-UInt32 $header 76  $imageType      # fixed = 2
Write-UInt32 $header 80  0              # image flags
# offset 84: 256 bytes description (zeros = empty)
Write-UInt32 $header 340 $preHeaderSize  # offset to BAT
Write-UInt32 $header 344 $dataOffset     # offset to data
Write-UInt32 $header 348 $cylinders      # geometry
Write-UInt32 $header 352 $heads
Write-UInt32 $header 356 $sectors
Write-UInt32 $header 360 512            # sector size
Write-UInt32 $header 364 0              # unused
Write-UInt64 $header 368 ([uint64]$rawSize)  # disk size
Write-UInt32 $header 376 $blockSize     # block size
Write-UInt32 $header 380 0              # block extra
Write-UInt32 $header 384 $blocksInHdd   # blocks in HDD
Write-UInt32 $header 388 $blocksInHdd   # blocks allocated (all, since fixed)
[Array]::Copy($uuid1, 0, $header, 392, 16)  # UUID
[Array]::Copy($uuid2, 0, $header, 408, 16)  # UUID snap

# Build BAT (Block Allocation Table) — for fixed images, sequential mapping
$bat = New-Object byte[] ($dataOffset - $preHeaderSize)
for ($i = 0; $i -lt $blocksInHdd; $i++) {
    Write-UInt32 $bat ($i * 4) ([uint32]$i)
}

# Write VDI file
Write-Host "Writing VDI file..." -ForegroundColor Cyan
$fs = [System.IO.File]::Create($VdiPath)
try {
    # Write header
    $fs.Write($header, 0, $header.Length)

    # Write BAT
    $fs.Write($bat, 0, $bat.Length)

    # Copy raw data
    $src = [System.IO.File]::OpenRead($RawPath)
    try {
        $bufSize = 4 * 1024 * 1024  # 4 MB buffer
        $buf = New-Object byte[] $bufSize
        $total = 0
        $lastPct = -1
        while ($true) {
            $read = $src.Read($buf, 0, $bufSize)
            if ($read -eq 0) { break }
            $fs.Write($buf, 0, $read)
            $total += $read
            $pct = [math]::Floor($total * 100 / $rawSize)
            if ($pct -ne $lastPct -and $pct % 10 -eq 0) {
                Write-Host "  $pct% ($([math]::Round($total / 1MB)) MB)" -ForegroundColor Gray
                $lastPct = $pct
            }
        }
    } finally {
        $src.Close()
    }
} finally {
    $fs.Close()
}

$vdiSize = (Get-Item $VdiPath).Length
Write-Host "`nDone! VDI created: $VdiPath ($([math]::Round($vdiSize / 1GB, 2)) GB)" -ForegroundColor Green
