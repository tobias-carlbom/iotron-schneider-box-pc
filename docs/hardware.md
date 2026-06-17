# Hardware Details

## Schneider Electric Magelis iPC (S-Box)

Compact fanless industrial Box PC designed for cabinet/panel mounting. Passively cooled via large external heatsink. Powered by 24 VDC (industrial standard).

### Specifications

| Component | Detail |
|-----------|--------|
| Model | HMIPCCB |
| Configuration | 1B2CD40010N00 |
| Serial | K1KF0168556 |
| DOM | Week 48, 2013 (1348) |
| CPU | Intel Core 2 Duo P8400 @ 2.26 GHz |
| Chipset | Intel GM45 Express |
| GPU | Intel GMA 4500MHD (integrated in chipset) |
| RAM | DDR3 SO-DIMM (slot on upper PCB) |
| Storage | 8 GB CompactFlash (IDE adapter) + 500 GB 2.5" SATA HDD |
| PSU | 24 VDC input via screw terminal, internal DC-DC conversion |
| Cooling | Fully passive (large heatsink on rear) + internal fan(s) |
| CMOS Battery | Renata CR2477N (3V lithium, front-accessible) |
| Main PCB | SPCB10_BX02-01, CPU-D4991G(B) |

### Rear Panel I/O

| Port | Type | Purpose |
|------|------|---------|
| Monitor/Panel | DVI | Display output (integrated Intel GMA) |
| ETH1 | RJ-45 GbE | Primary network |
| ETH2 | RJ-45 GbE | Secondary network |
| COM1 | DB-9 RS-232 | Serial communication (PLC/WAGO) |
| COM2 | DB-9 RS-232 | Serial communication |
| USB2 | USB-A | Rear USB port |
| Slot 1 | PCIe/PCI | Expansion (Intel NIC D33025 installed) |
| Slot 2 | PCIe/PCI | Expansion (empty) |
| Audio | 3.5mm | MIC, Line IN, Line OUT |

### Front Panel

| Feature | Purpose |
|---------|---------|
| DVD-RW | Slide-In Slot 1 (optical drive) |
| CF Card Slot | CompactFlash boot media |
| USB Port | Front USB (used for license dongle) |
| Security Key Slot | Hardware dongle mount |
| CMOS Profile Switch | Rotary switch (0-F) for BIOS profile selection |
| Reset Button | Hardware reset |
| Power LED | Green when powered |
| Link 2 LED | Orange when network active |
| Disk LED | Storage activity indicator |
| BATTERY | Front-accessible CMOS battery compartment |

### Internal Components

| Component | Detail |
|-----------|--------|
| HDD | Western Digital WD5000LUCT (WD AV-25 series, 2.5" SATA, 500 GB) |
| Network module | Pulse H5007NL (Ethernet magnetics/transformer) |
| PCIe NIC | Intel D33025 (additional dual-port Ethernet) |
| Fan kit | HMIYPFKT061 (Schneider optional accessory) |

### Physical Connections in Production

| Cable | Purpose |
|-------|---------|
| 24 VDC power | From cabinet power supply |
| Ethernet Cable 1 | Camera network (192.168.3.x) |
| Ethernet Cable 2 | Junction box / machine network (192.168.0.x) |
| Ethernet Cable 3 | Factory/plant network (10.202.71.x, 192.168.20.x, 192.168.1.x) |
| COM port cable | WAGO PLC / serial device communication |

### Manual Reference

Schneider Electric document **EIO0000001744** — Chapter 6 "Hardware Extensions" covers:
- Removing the cover
- Internal view
- Main memory (RAM) installation
- PCI expansion board installation
- CF card installation and removal
