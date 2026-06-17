# Grafikscan 2200 - VirtualBox Setup Guide

## Overview

Run the Grafikscan XP Embedded system in VirtualBox on any modern Windows PC.
This replaces the dead Schneider Magelis iPC while keeping the exact same software.

## What you need

- **PC**: Any modern desktop with 8GB+ RAM, Ethernet, 4+ USB ports
- **VirtualBox**: https://www.virtualbox.org/wiki/Downloads (free)
- **Extension Pack**: Same download page - needed for USB 2.0 passthrough
- **USB-to-RS232 adapters**: 2x (for PLC and serial devices)
- **Ethernet**: For camera network (192.168.3.101)

## Quick Setup

```powershell
# 1. Install VirtualBox + Extension Pack

# 2. Run the setup script
cd C:\Users\tobias\source\repos\iotron-schneider-box-pc\vm
.\setup-virtualbox.ps1

# 3. Start the VM
VBoxManage startvm "Grafikscan 2200 - XP Embedded"
```

## Network Configuration

The Grafikscan system communicates with three devices:

| Device | IP Address | Network | Connection |
|--------|-----------|---------|------------|
| PC cassetta (junction box) | 192.168.0.147 | 192.168.0.0/24 | Ethernet |
| PLC Wago | 192.168.0.145 | 192.168.0.0/24 | RS-232 serial |
| Telecamera (camera) | 192.168.3.101 | 192.168.3.0/24 | Ethernet |

### For testing (without hardware)
NAT networking is fine - the VM gets internet access for testing.

### For production (with camera + PLC)
Switch to **bridged networking** so the VM gets a real IP on the physical network:

```powershell
# List available adapters
VBoxManage list bridgedifs

# Set bridged mode (replace adapter name)
VBoxManage modifyvm "Grafikscan 2200 - XP Embedded" --nic1 bridged --bridgeadapter1 "Ethernet"
```

The XP guest already has a static IP configured. You may need two NICs if the camera (192.168.3.x) and PLC (192.168.0.x) are on separate physical networks:

```powershell
VBoxManage modifyvm "Grafikscan 2200 - XP Embedded" --nic2 bridged --bridgeadapter2 "Ethernet 2" --nictype2 Am79C973
```

## USB Passthrough (RS-232 Adapters)

1. Plug in USB-to-RS232 adapter to the host PC
2. In VirtualBox window: **Devices > USB > [select adapter]**
3. The adapter appears as a COM port inside XP

For permanent assignment (auto-connect on VM start):

```powershell
# Find the adapter's VID:PID
VBoxManage list usbhost

# Add filter (example for Prolific PL2303)
VBoxManage usbfilter add 0 --target "Grafikscan 2200 - XP Embedded" --name "RS232-1" --vendorid 067b --productid 2303
VBoxManage usbfilter add 1 --target "Grafikscan 2200 - XP Embedded" --name "RS232-2" --vendorid 067b --productid 2303
```

## Guest Additions (Mouse + Display)

After XP boots:
1. Menu: **Devices > Insert Guest Additions CD Image**
2. Inside XP: Run `D:\VBoxWindowsAdditions.exe`
3. Reboot XP
4. Mouse integration and better display resolution will work

## Disk Image Details

- **Source**: `grafikscan_cf.img` (raw CF card image, 7.6 GB)
- **Converted**: `grafikscan_cf.vdi` (VirtualBox format)
- **Partitions**: P1=DATA(FAT,3GB), P2=OS_XPE(FAT32,4.8GB)
- **Boot**: MBR → P1(ntldr) → boot.ini → P2(WINDOWS)
- **Write filter**: EWF (Enhanced Write Filter) active - changes are lost on reboot

## Troubleshooting

**VM won't boot**: Make sure IDE controller (PIIX4) is used, not SATA/AHCI. The XP image has native IDE drivers.

**No mouse**: Install Guest Additions (see above). Without them, click inside VM window and press Right Ctrl to release mouse.

**Blue screen (BSOD)**: The image has AHCI drivers injected for physical hardware. In VirtualBox with IDE emulation this shouldn't happen. If it does, boot in Safe Mode (F8) and disable the iaStor service.

**Network timeout in Aggiorna**: The launcher pings 192.168.0.147, 192.168.0.145, 192.168.3.101 before starting Grafikscan. Without these devices, it will timeout. This is normal behavior.
