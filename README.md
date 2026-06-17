# Schneider Electric Magelis iPC — Grafikscan 2200 Recovery

Industrial web inspection camera system used for real-time print quality monitoring at Hedlunds Papper.

## System Overview

| Field | Value |
|-------|-------|
| **Model** | Schneider Electric Magelis iPC (S-Box) |
| **Part Number** | HMIPCCB |
| **Configuration** | 1B2CD40010N00 |
| **Serial Number** | K1KF0168556 |
| **Manufactured** | Week 48, 2013 |
| **Power** | 24 VDC / 1–6 A |
| **CPU** | Intel Core 2 Duo P8400 (2.26 GHz) |
| **Chipset** | Intel GM45 |
| **Graphics** | Intel GMA 4500MHD (integrated) |
| **RAM** | DDR3 SO-DIMM |
| **OS** | Windows XP Embedded (built 2012-03-09) |
| **Computer Name** | GKS22-058-14B |
| **Software** | Grafikscan 2100/3000 by Grafikontrol S.p.A. (Milan) |

## Status

**Motherboard is dead.** Power LED lights up but POST never begins — no fan spin, no video signal, draws only 0.475A at 24V (normal would be 15–25W+). CMOS battery tested OK at 3.07V (Renata CR2477N).

## Storage Media

| Media | Content | Status |
|-------|---------|--------|
| **CF Card 8 GB** | Windows XP Embedded + Grafikscan software | Fully readable, cloned to `grafikscan_cf.img` |
| **HDD 500 GB** (WD5000LUCT) | Inspection data only (images, logs) — no OS | Cloned to 750 GB HDD |
| **USB Dongle** | License key (likely HASP/Sentinel) | Unidentified — not a storage device |
| **Intel PCIe NIC** (D33025) | Additional network adapter | Removed from system |

## CF Card Partition Layout

| # | Label | Filesystem | Size | Content |
|---|-------|------------|------|---------|
| 1 | DATA | FAT | ~3.0 GB | Boot loader (ntldr, boot.ini) + Grafikscan application |
| 2 | OS XPE | FAT32 | ~4.7 GB | Windows XP Embedded + drivers + EWF |
| 3 | (none) | Unknown | 64 KB | Marker/padding |

## Documentation

- [Hardware Details](docs/hardware.md) — Motherboard, peripherals, physical connections
- [Software Stack](docs/software-stack.md) — All installed software and their purpose
- [Network Configuration](docs/network-config.md) — IP addresses, routing, port assignments
- [CF Card Analysis](docs/cf-card-analysis.md) — Complete filesystem analysis
- [Troubleshooting Log](docs/troubleshooting-log.md) — Diagnostic steps taken and results
- [VM Setup Guide](docs/vm-setup.md) — Running the system as a virtual machine
- [Recovery Plan](docs/recovery-plan.md) — Options for getting the system back online

## Key Contacts

| Who | Contact | Purpose |
|-----|---------|---------|
| **Grafikontrol S.p.A.** | helpdesk@grafikontrol.it / +39.02.210095.1 | Camera system manufacturer (Milan) |
| **Schneider Electric SE** | +46 8 5500 1700 | Box PC manufacturer |
| **3S-Smart Software** | support@3s-software.com | CoDeSys/WAGO PLC license |
| **Customer** | flexohpi@hedlundspapper.se | System owner |

## Backups

| Artifact | Location | Size |
|----------|----------|------|
| CF card raw image | `grafikscan_cf.img` | 7.63 GB |
| HDD clone | Physical 750 GB HDD | 500 GB |
