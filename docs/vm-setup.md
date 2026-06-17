# VM Setup Guide

Run the Grafikscan system as a virtual machine using the CF card disk image.

## Prerequisites

- VMware Workstation Pro 17 (installed)
- CF card raw image: `grafikscan_cf.img` (8,191,475,712 bytes)
- Git Bash `dd.exe` (available at `C:\Program Files\Git\usr\bin\dd.exe`)

## Step 1 — Convert Raw Image to VMDK

The CF card image is a raw disk dump. Convert it to VMware's VMDK format:

```powershell
# Using vmware-vdiskmanager to create a VMDK from raw image
& "C:\Program Files (x86)\VMware\VMware Workstation\vmware-vdiskmanager.exe" `
    -r "C:\Users\tobias\Desktop\Grafikscan\grafikscan_cf.img" `
    -t 0 `
    "C:\Users\tobias\Desktop\Grafikscan\grafikscan_cf.vmdk"
```

Note: `-t 0` creates a single growable virtual disk.

If vmware-vdiskmanager doesn't accept raw input directly, use qemu-img:

```powershell
# Install qemu-img via winget
winget install qemu.qemu

# Convert raw to VMDK
qemu-img convert -f raw -O vmdk `
    "C:\Users\tobias\Desktop\Grafikscan\grafikscan_cf.img" `
    "C:\Users\tobias\Desktop\Grafikscan\grafikscan_cf.vmdk"
```

## Step 2 — Create VMware VM

Create a new VM with these settings:

| Setting | Value |
|---------|-------|
| Guest OS | Windows XP Professional (32-bit) |
| Firmware | BIOS (not UEFI) |
| RAM | 1024 MB |
| CPU | 1 socket, 2 cores |
| Disk Controller | **IDE** (critical — XP Embedded expects IDE, not SCSI/SATA) |
| Network | Bridged or NAT |
| Display | VGA compatible |
| USB | USB 1.1 (for dongle passthrough later) |
| Sound | Disabled |
| CD/DVD | Disabled |

### Attach the VMDK

1. Remove the default hard disk from the new VM
2. Add existing hard disk → select `grafikscan_cf.vmdk`
3. Ensure it's on **IDE 0:0** (not SCSI)

## Step 3 — BIOS Configuration

Before first boot, enter the VM BIOS (press F2 at VMware splash):

1. Boot order: Hard Drive first
2. IDE configuration: auto-detect
3. No Plug and Play OS

## Step 4 — First Boot

Expected behavior:
1. BIOS POST
2. ntldr loads from partition 1
3. Windows XP Embedded loads from partition 2
4. EWF activates (overlay on OS partition)
5. Grafikscan2100.exe may attempt to start

### Likely Issues

**Blue Screen (STOP 0x7B — INACCESSIBLE_BOOT_DEVICE)**
The XP Embedded image was built for Intel GM45 SATA/IDE controller. VMware's emulated IDE should be compatible, but if not:
- Try adding `intelide.sys` and `pciide.sys` to the registry offline
- Use VMware's "Legacy" IDE emulation

**Driver mismatch**
XP Embedded images contain only drivers for the target hardware. VMware's virtual hardware (AMD PCnet / E1000 NIC, VMware SVGA) may not have drivers.
- Install VMware Tools after successful boot (provides SVGA, mouse, network drivers)
- Network will likely not work until VMware Tools is installed

**Grafikscan startup failure**
The application expects:
- Matrox frame grabber hardware → will fail with "device not found"
- JAI camera on GigE → will fail
- COM port for WAGO PLC → can be emulated via VMware serial port passthrough
- USB license dongle → requires USB passthrough in VM settings
- Specific IP addresses configured → will need network adapter configuration

These failures are expected — the goal is to explore the OS, software, and configuration, not run the full camera system.

## Step 5 — Optional: Add HDD Data

To also access the 500 GB inspection data in the VM:

1. Create a VMDK from the HDD clone (same process as Step 1)
2. Attach as second IDE disk (IDE 0:1 or IDE 1:0)
3. It should appear as the D: or E: drive in XP

## USB Dongle Passthrough

To test the license dongle:
1. Connect the USB dongle to the host PC
2. In VMware: VM → Removable Devices → find the dongle → Connect to VM
3. The dongle should appear in Device Manager inside XP
4. This will reveal the dongle type (HASP, Sentinel, CodeMeter, etc.)
