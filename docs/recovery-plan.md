# Recovery Plan

## Goal

Restore the Grafikscan 2200 web inspection system to working condition for Hedlunds Papper's printing press.

## Options (in order of preference)

### Option 1 — Replace Motherboard / Box PC

**Best outcome**: Drop-in replacement using existing CF card, HDD, dongle, and PCIe NIC.

| Action | Contact |
|--------|---------|
| Contact Grafikontrol for replacement PC or compatible hardware | helpdesk@grafikontrol.it, +39.02.210095.1 |
| Contact Schneider Electric for HMIPCCB repair/replacement | +46 8 5500 1700, quote SN K1KF0168556 |
| Search for used HMIPCC S-Box on industrial surplus dealers | Radwell, EU Automation, Ellebizeta |

**Requirements for compatible replacement**:
- Intel-based platform (ideally same GM45 chipset)
- BIOS with IDE-mode SATA support
- CompactFlash IDE adapter (or CF-to-SATA adapter)
- 24 VDC power input
- DVI video output
- At least 2x GbE + 1x PCIe slot (or 3x GbE)
- 2x COM ports (RS-232)
- USB for license dongle

### Option 2 — Rebuild on Different Hardware

If an identical replacement cannot be found, rebuild on a compatible platform.

**Requirements**:
1. CF card image boots on the new hardware (test in VM first)
2. BIOS supports IDE-mode boot from CF adapter
3. XP Embedded must detect the new hardware — may need driver injection
4. USB dongle must be recognized
5. Matrox frame grabber PCIe card must be compatible (if camera hardware still works)

**Steps**:
1. Boot CF image in VMware VM to verify OS + software integrity
2. Identify USB dongle type via VM passthrough
3. Find an industrial PC with compatible specs
4. Test CF card boot on the new hardware
5. If BSOD 0x7B: modify registry to add generic IDE/AHCI drivers before boot
6. Install missing drivers for new platform
7. Verify Grafikscan starts (may fail without camera hardware — that's OK)
8. Deploy to production with camera hardware connected

### Option 3 — Contact Grafikontrol for Full System Replacement

Grafikontrol may offer a complete upgraded system (newer Grafikscan model).

**Current product line** (replaces Grafikscan 2200):
- Matrix Plus
- Lynex Plus
- Progrex Plus

This is the most expensive option but gives a supported, modern system with warranty.

## Immediate Actions

| Priority | Action | Status |
|----------|--------|--------|
| 1 | Clone CF card to raw image | Done (grafikscan_cf.img) |
| 2 | Clone 500 GB HDD | Done (750 GB HDD) |
| 3 | Document all software, config, and network settings | Done |
| 4 | Boot CF image in VMware VM | Pending |
| 5 | Identify USB dongle type | Pending |
| 6 | Contact Grafikontrol for support/replacement options | Pending |
| 7 | Contact Schneider Electric for PC repair/replacement | Pending |
| 8 | Ask customer for dxdiag/msinfo32 from the working unit | Pending |

## Remaining Diagnostics on Dead Unit

These are low-probability but worth trying:

1. Set CMOS Profile rotary switch to position 0 (factory default)
2. Reseat RAM module (SO-DIMM)
3. Try booting with all peripherals removed (no PCIe NIC, no HDD, no CF)
4. Measure internal voltage rails with multimeter
5. Listen for beep codes with PC speaker connected

## Data Preservation

| Item | Backup Location | Verified |
|------|----------------|----------|
| CF card (OS + software) | grafikscan_cf.img (Desktop\Grafikscan\) | Yes |
| HDD (inspection data) | Physical 750 GB clone | Yes |
| USB dongle | Original hardware (keep safe!) | N/A |
| Intel PCIe NIC | Original hardware (removed from slot) | N/A |
| CMOS battery | Original (Renata CR2477N, 3.07V) | Tested OK |
| Documentation | This repository | Yes |
