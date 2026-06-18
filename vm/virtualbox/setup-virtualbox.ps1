# Grafikscan 2200 - VirtualBox Setup Script
# Converts raw CF image and creates XP VM with proper settings
#
# Prerequisites:
#   1. Install VirtualBox from https://www.virtualbox.org/wiki/Downloads
#   2. Also install the "VirtualBox Extension Pack" (same page) - needed for USB 2.0 passthrough
#   3. Run this script from the vm\ directory

param(
    [string]$BridgeAdapter = ""
)

$ErrorActionPreference = "Stop"
$vmDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$imgPath = Join-Path $vmDir "grafikscan_cf.img"
$vdiPath = Join-Path $vmDir "grafikscan_cf.vdi"
$vmName = "Grafikscan 2200 - XP Embedded"

$vboxManage = "C:\Program Files\Oracle\VirtualBox\VBoxManage.exe"
if (-not (Test-Path $vboxManage)) {
    $cmd = Get-Command VBoxManage -ErrorAction SilentlyContinue
    if ($cmd) { $vboxManage = $cmd.Source }
    else {
        Write-Host "ERROR: VirtualBox not found. Install from https://www.virtualbox.org/wiki/Downloads" -ForegroundColor Red
        exit 1
    }
}

# Step 1: Convert raw image to VDI
if (-not (Test-Path $vdiPath)) {
    Write-Host "Converting raw image to VDI format..." -ForegroundColor Cyan
    & $vboxManage convertfromraw $imgPath $vdiPath --format VDI
    if ($LASTEXITCODE -ne 0) { Write-Host "ERROR: Conversion failed" -ForegroundColor Red; exit 1 }
    # Resize VDI slightly to fix CHS geometry (995→996 cylinders).
    # Without this, BIOS INT13h rejects reads to the EWF partition at cylinder 995.
    & $vboxManage modifymedium disk $vdiPath --resize 7814
    Write-Host "Done: $vdiPath" -ForegroundColor Green
} else {
    Write-Host "VDI already exists, skipping conversion." -ForegroundColor Yellow
}

# Step 2: Remove existing VM if present
$existing = & $vboxManage list vms 2>&1 | Select-String -Pattern ([regex]::Escape($vmName))
if ($existing) {
    Write-Host "Removing existing VM '$vmName'..." -ForegroundColor Yellow
    & $vboxManage unregistervm $vmName --delete 2>$null
}

# Step 3: Create VM
Write-Host "Creating VM '$vmName'..." -ForegroundColor Cyan
& $vboxManage createvm --name $vmName --ostype WindowsXP --register
if ($LASTEXITCODE -ne 0) { Write-Host "ERROR: Failed to create VM" -ForegroundColor Red; exit 1 }

# Step 4: Configure VM settings
Write-Host "Configuring VM settings..." -ForegroundColor Cyan

# Basic settings: 1GB RAM, 1 CPU, BIOS, ACPI+IOAPIC, VBoxVGA graphics
# CRITICAL: Must be 1 CPU with ACPI+IOAPIC — the XPe image uses ACPI uniprocessor HAL.
# Wrong HAL config causes invisible BSOD (kernel halt before display init).
& $vboxManage modifyvm $vmName `
    --memory 2048 `
    --vram 64 `
    --cpus 1 `
    --firmware bios `
    --acpi on `
    --ioapic on `
    --graphicscontroller VBoxVGA `
    --audio-driver none `
    --clipboard-mode bidirectional `
    --rtc-use-utc off `
    --boot1 disk --boot2 none --boot3 none --boot4 none

# USB 2.0 (EHCI) - requires Extension Pack
Write-Host "Enabling USB 2.0 (EHCI)..." -ForegroundColor Cyan
try {
    & $vboxManage modifyvm $vmName --usb on --usb-ehci on
} catch {
    Write-Host "WARNING: USB 2.0 (EHCI) failed - install VirtualBox Extension Pack" -ForegroundColor Yellow
    & $vboxManage modifyvm $vmName --usb on
}

# Step 5: Storage - IDE controller with PIIX4 (native XP support, no extra drivers needed)
Write-Host "Setting up IDE storage controller..." -ForegroundColor Cyan
& $vboxManage storagectl $vmName --name "IDE" --add ide --controller PIIX4

# Attach the disk image
& $vboxManage storageattach $vmName `
    --storagectl "IDE" --port 0 --device 0 `
    --type hdd --medium $vdiPath

# Step 6: Networking
# List available bridged adapters
Write-Host "`nAvailable network adapters for bridging:" -ForegroundColor Cyan
& $vboxManage list bridgedifs | Select-String -Pattern "^Name:" | ForEach-Object { Write-Host "  $_" }

if ($BridgeAdapter -eq "") {
    # Default: NAT for initial testing (always works)
    Write-Host "`nUsing NAT for initial testing. Change to bridged later for production." -ForegroundColor Yellow
    & $vboxManage modifyvm $vmName --nic1 nat --nictype1 Am79C973
} else {
    Write-Host "`nUsing bridged adapter: $BridgeAdapter" -ForegroundColor Green
    & $vboxManage modifyvm $vmName --nic1 bridged --bridgeadapter1 $BridgeAdapter --nictype1 Am79C973
}

# Step 7: Serial port (optional - if you want to emulate COM ports instead of USB passthrough)
# Uncomment if needed:
# & $vboxManage modifyvm $vmName --uart1 0x3F8 4 --uart-mode1 server "\\.\pipe\grafikscan_com1"
# & $vboxManage modifyvm $vmName --uart2 0x2F8 3 --uart-mode2 server "\\.\pipe\grafikscan_com2"

Write-Host "`n========================================" -ForegroundColor Green
Write-Host " VM '$vmName' created successfully!" -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Green
Write-Host ""
Write-Host "NEXT STEPS:" -ForegroundColor Cyan
Write-Host ""
Write-Host "1. Start the VM:"
Write-Host "   VBoxManage startvm `"$vmName`""
Write-Host ""
Write-Host "2. Install VirtualBox Guest Additions (in XP):"
Write-Host "   Menu: Devices > Insert Guest Additions CD Image"
Write-Host "   Then run D:\VBoxWindowsAdditions.exe inside XP"
Write-Host ""
Write-Host "3. For production - switch to bridged networking:"
Write-Host "   VBoxManage modifyvm `"$vmName`" --nic1 bridged --bridgeadapter1 `"<adapter-name>`""
Write-Host ""
Write-Host "4. USB passthrough for RS-232 adapters:"
Write-Host "   - Plug in USB-to-RS232 adapter"
Write-Host "   - In VirtualBox: Menu > Devices > USB > select the adapter"
Write-Host "   - Or add a permanent USB filter:"
Write-Host "     VBoxManage usbfilter add 0 --target `"$vmName`" --name `"RS232`" --vendorid <VID> --productid <PID>"
Write-Host ""
Write-Host "5. Set static IP in XP guest to match production network:"
Write-Host "   Production IPs:"
Write-Host "   - PC cassetta:  192.168.0.147"
Write-Host "   - PLC Wago:     192.168.0.145"
Write-Host "   - Telecamera:   192.168.3.101"
Write-Host ""
