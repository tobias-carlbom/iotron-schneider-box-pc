# Software Stack

## Operating System

**Windows XP Embedded (XPe)**
- Build date: 2012-03-09
- SKU: XPeCli (XP Embedded Client)
- Product ID: M37TW-6JHTG-2FKG6-MQQMY-2YTW3
- Runtime GUID: {415583CF-FB09-4E34-A1BD-E27743CE310C}
- Enhanced Write Filter (EWF) enabled on OS partition — all runtime writes go to RAM overlay
- RAM Disk: 890 MB NTFS volume (M: drive) created at boot via ImDisk

## Main Application

### Grafikscan 2100 (Console)
- **Executable**: `Grafikscan2100.exe` (6,068,224 bytes, 2015-06-05)
- **Backup**: `Grafikscan2100old.exe` (5,947,904 bytes, 2015-01-13)
- **System version**: SD25 04A/09
- **Application version**: G21P4038
- **Developer**: Grafikontrol S.p.A., Milan, Italy
- **Built with**: Borland C++ Builder (`.bpr` project files found)

### Key DLLs
| File | Purpose |
|------|---------|
| ATCore.dll | Core application framework |
| ATMilHelper.dll | Matrox MIL integration helper |
| Gk_W32_Sapera.dll | DALSA Sapera frame grabber interface |
| DistortionRemover.dll | Image distortion correction |
| uart.dll | Serial port communication |
| stlpmt45.dll | STLport C++ standard library |

### Application Passwords
| Level | Password | Access |
|-------|----------|--------|
| User | GK | Operator areas |
| Service | 11079 | Technician areas |
| Super User | 11079 | Full access |

### Grafikscan 3000
- **GkDaemon**: Background service (`GkDaemon.exe`, 472 KB)
- Moxa NE-4110 serial device server configuration
- Camera Link serial interface (`clallserial.dll`)
- Source code included (Borland C++ Builder)

## Camera & Frame Grabber

### Matrox Imaging Library (MIL)
- Location: `D:\Program Files\Matrox Imaging\`
- Includes: MIL SDK, drivers, tools, examples
- Frame grabber drivers: Solios, Concord GigE
- License Manager: `LicenseManager.exe`
- milconfig, MILInfo diagnostic tools

### DALSA Sapera LT
- Location: `D:\DALSA\Sapera\`
- Full SDK with help, examples, demos, classes
- Sapera Processing library
- Camera files in `CamFiles\`
- Integration via `Gk_W32_Sapera.dll`

### JAI Camera SDK
- Location: `D:\Program Files\JAI\SDK\`
- GigE Filter Driver for JAI cameras
- SDK libraries, tools, samples, documentation
- Camera connected via GigE (Camera Link serial for control)

### Camera Link
- Serial interface DLL: `clsercor.dll` (D:\CameraLink\Serial\)
- Used for camera control commands over Camera Link

## PLC / Automation

### WAGO Software / CoDeSys
- Location: `D:\Program Files\WAGO Software\`
- CoDeSys 2.3.9.28 (PLC programming environment)
- WAGO-IO-PRO 32 configuration
- CoDeSys OPC server configured
- **License**: CoDeSys Standard Web Server (3S-Smart Software Solutions GmbH)
  - License key: `cac9ni-pj1tdr-zwlmnw-0hjigo`
  - Mode: Licensed

### B&R Automation
- Location: `D:\Program Files\BrAutomation\`
- B&R automation runtime/tools

### Moxa NE-4110
- NPort Driver Manager: `D:\Program Files\NPortDrvManager\`
- Network Enabler Administrator: `D:\Program Files\Network Enabler Administrator\`
- Serial device server for COM port over Ethernet

## Remote Access

| Software | Location | Purpose |
|----------|----------|---------|
| UltraVNC | `D:\Program Files\UltraVNC\` | Remote desktop (primary) |
| OpenVPN | `D:\Program Files\OpenVPN\` | VPN tunnel to factory network |
| TeamViewer | `D:\Program Files\TeamViewer\` | Remote support (installed 2017) |

## Utilities

| Software | Purpose |
|----------|---------|
| ImDisk | RAM disk driver (creates M: at boot) |
| Qsoft RAMDisk | Alternative RAM disk (in Sw_PC) |
| ZipGenius 6 | Archive/compression |
| Adobe Acrobat Reader 7.08 | PDF viewing |
| 3M MicroTouch | Touch screen drivers |
| Realtek HD Audio | Audio drivers (Realtek ALC series) |
| Intel GFX | Intel integrated graphics driver |

## Boot Sequence

1. BIOS loads from CF card (IDE-mode CompactFlash)
2. CMOS Profile switch selects BIOS configuration (rotary 0-F)
3. MBR → `ntldr` from partition 1 (E: DATA)
4. `boot.ini` loads XP Embedded from partition 2 (D: OS XPE)
5. EWF overlay activates (RAM-based write filter on OS partition)
6. ImDisk creates 890 MB RAM disk as M: drive
7. Network routes configured via startup scripts
8. Grafikscan2100.exe launches
