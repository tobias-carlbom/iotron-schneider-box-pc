# CF Card Analysis

## Physical Media

- **Type**: CompactFlash 8 GB
- **Interface**: IDE adapter on motherboard (BIOS sees it as IDE HDD)
- **Backup**: Raw disk image `grafikscan_cf.img` (8,191,475,712 bytes)

## Partition Table (MBR)

| Partition | Drive Letter | Label | Filesystem | Size | Offset |
|-----------|-------------|-------|------------|------|--------|
| 1 | E: | DATA | FAT | 3,150,249,984 (~2.93 GB) | 32,256 |
| 2 | D: | OS XPE | FAT32 | 5,033,871,360 (~4.69 GB) | 3,150,282,240 |
| 3 | — | — | Unknown | 64,512 (64 KB) | 8,184,153,600 |

## Boot Configuration

`E:\boot.ini`:
```ini
[boot loader]
timeout=0
default=multi(0)disk(0)rdisk(0)partition(2)\WINDOWS
[operating systems]
multi(0)disk(0)rdisk(0)partition(2)\WINDOWS="Microsoft Windows XP Embedded" /fastdetect /noexecute=AlwaysOff
```

Boot sequence: BIOS → Partition 1 (ntldr) → Partition 2 (WINDOWS)

## Partition 1 — DATA (E:)

Boot loader and Grafikscan application data.

### Root Files
| File | Purpose |
|------|---------|
| ntldr | Windows NT Loader |
| NTDETECT.COM | Hardware detection |
| boot.ini | Boot configuration |
| WERUNTIME.INI | XPe runtime config (GUID, PID, build date) |
| ComputerName.ini | Hostname: GKS22-058-14B |
| G21S4000.ver | Build timestamp: 03/21/2012 6:18:00 PM |
| clstub.bin | Camera Link stub |
| PDOXUSRS.NET | Paradox database user list |

### Key Directories

| Directory | Content |
|-----------|---------|
| Grafikscan2100/ | Main application (console, images, config, jobs) |
| Grafikscan3000/ | Secondary application (GkDaemon, Moxa config, Camera Link serial) |
| Lavori/ | Job/recipe storage |
| Sharing/ | Shared data |
| Aggiorna/ | Updates (Italian: "Update") |
| VERSIONEDVD/ | System version info (SD25 04A/09) |
| AUTORUN/ | CD autorun for software distribution |
| lm.dat/ | CoDeSys license manager data |

### Grafikscan2100 Application Structure

```
Grafikscan2100/
├── Applicazione/
│   ├── Console/
│   │   ├── Eseguibile/     ← Main executables
│   │   │   ├── Grafikscan2100.exe (6.0 MB, 2015-06-05)
│   │   │   ├── Grafikscan2100old.exe (5.9 MB, 2015-01-13)
│   │   │   ├── ATCore.dll, ATMilHelper.dll, Gk_W32_Sapera.dll
│   │   │   ├── DistortionRemover.dll, uart.dll
│   │   │   ├── StaticIpAddressUsed.ini
│   │   │   ├── ImpostazioniIniziali.txt
│   │   │   └── *.cmd (network scripts)
│   │   ├── Help/
│   │   ├── Dati/            ← Runtime data
│   │   └── Bmp/             ← UI bitmaps
│   ├── Versioni/            ← G21P4038.VER
│   ├── Logs/
│   ├── Lingua/              ← Language/translation files
│   ├── Gallery/
│   ├── DR/                  ← Defect reports
│   ├── ColorCalib/          ← Color calibration
│   ├── I7565/               ← ICP DAS I-7565 USB-CAN
│   └── Wagoplc/             ← WAGO PLC programs
├── Images/                  ← Inspection images
├── Lavori/                  ← Jobs/recipes
├── Temp/
├── Testa/                   ← Test data
├── TcpModbus/               ← Modbus TCP communication
├── Pct/
├── LeutronVision/           ← Leutron frame grabber (alternative)
├── Jai/                     ← JAI camera config
├── I7565/                   ← USB-CAN interface
├── GKSaperaDll/             ← Sapera DLL files
├── FireGrab/                ← FireWire grabber (alternative)
├── Film/
├── DatiPressioni/           ← Pressure data
├── CAN/                     ← CAN bus communication
└── AFGCamera/               ← Active frame grabber camera
```

### handle.txt
Contains value `65766` — modified 2026-04-07. Likely a handle counter or running total (most recently written value before system died).

## Partition 2 — OS XPE (D:)

Windows XP Embedded installation.

### Root Directories
| Directory | Content |
|-----------|---------|
| WINDOWS/ | Full XP Embedded OS |
| Program Files/ | Installed applications (see software-stack.md) |
| Documents and Settings/ | User profiles |
| Intel/ | Intel GFX driver logs |
| DALSA/ | Sapera LT SDK |
| CameraLink/ | Camera Link serial DLL |
| Ewf/ | EWF registry configuration files |
| Sw_PC/ | Installation packages (drivers, tools) |
| SecondaryHDD/ | Mount point for 500 GB HDD |
| WallPapers/ | Desktop wallpapers |
| Task Bar/ | Taskbar customization |
| Shutdown/ | Shutdown/reboot/RAMdisk scripts |

### EWF Configuration

`D:\Ewf\Arc.reg` — Protects partition 2 (OS):
```
Volume0: multi(0)disk(0)rdisk(1)partition(2)
Type: 1 (RAM overlay)
```

`D:\Ewf\PVDisk.reg` — EWF FBA settings:
```
EwfEnable: 1
PVDisk: 1
PVPart: 2
PVType: 1 (RAM-based)
LazyWrite: 0
```

### Shutdown Scripts

| Script | Command |
|--------|---------|
| Shutdown.cmd | `shutdown.exe -s -t 00` |
| Reboot.cmd | `shutdown.exe -r -t 00` |
| ramdisk.cmd | `imdisk -a -s 890M -m M: -p "/fs:ntfs /q /y"` |

### Software Packages in Sw_PC/

| Package | Purpose |
|---------|---------|
| Audio\Drivers\ | Realtek HD Audio (ALC series) |
| Wago\CoDeSys 2.3.9.28.zip | PLC programming environment |
| Acrobat Reader\ | Adobe Reader 7.08 |
| Microsoft KeyFix\ | KB958644 hotfix |
| ZipGenius\ | Archive tool |
| RamDisk\ | ImDisk + Qsoft RAMDisk |
| TouchScreen 3M\ | 3M MicroTouch driver |
