# Troubleshooting Log

## Timeline

### 2026-06-15 — Initial Report from Customer

**Customer**: Flexohpi (flexohpi@hedlundspapper.se)

**Reported symptoms**:
- Screen went black during lunch break
- Power indicator LEDs are lit but nothing happens
- Restart does not help
- No DOS prompt or any graphics visible — screen completely black
- Monitor reports "signal missing"
- They have an identical working unit on another machine

**Customer observations**:
- 500 GB HDD appears to have no OS or inspection software
- Suspects 8 GB CompactFlash has OS + software
- USB stick cannot be read on Win 11 (suspected license dongle)
- Software identified as "Grafikscan 2200" by Grafikontrol
- OS is Windows XP (SP unknown)
- Three Ethernet cables + one COM port cable connected
- Visually inspected motherboard from top — no visible burnt circuits
- Could not remove the board to inspect underside

### 2026-06-17 — Unit Arrived for Diagnosis

**Initial observations**:
- Model identified: Schneider Electric Magelis iPC HMIPCCB
- Powered via lab PSU at 24V DC
- Current draw: 0.475A (~11.4W) — abnormally low for a running system
- Power LED: Green (lit)
- Link 2 LED: Orange (lit) — network controller has power
- Fan(s): **Not spinning** — critical finding
- Video output: DVI port (not VGA as initially assumed) — no signal

**Interpretation**: System receives power but never initiates POST. CPU/chipset never starts, fans don't spin, no video signal. The motherboard has power on standby rails but the main power-on sequence never begins.

### Physical Inspection

1. **Opened unit** — followed Schneider manual chapter 6
2. **Capacitors**: Visually inspected — tops are flat and clean, no swelling or leakage
3. **CMOS Battery**: Removed and tested — Renata CR2477N reading 3.07V (healthy, nominal 3.0V)
4. **CMOS Profile Switch**: Pink rotary switch (0-F) visible on motherboard — selects BIOS profile
5. **PCIe NIC**: Removed Intel D33025 network card
6. **HDD**: Removed WD5000LUCT — no change in behavior

### Storage Media Verification

| Test | Result |
|------|--------|
| HDD connected to external PC | Readable. Contains only data (images, logs). No OS. |
| CF card connected to Windows 11 | Fully readable. Two partitions: OS XPE (FAT32) + DATA (FAT). |
| CF card contents | Complete XP Embedded + Grafikscan installation intact. |
| USB dongle | Not yet tested in detail. Shows up as unknown device (not a storage device). |

## Diagnosis

### Confirmed
- Motherboard does not complete POST
- Power supply is delivering correct voltage (24V DC)
- CMOS battery is healthy
- CF card is fully intact with complete OS + application
- HDD is healthy with data intact
- Network controller has standby power (Link LED lit)

### Ruled Out
- Power supply failure (LEDs lit, correct voltage)
- CMOS battery death (3.07V)
- CF card corruption (fully readable, all files intact)
- HDD failure (readable, data intact)

### Most Likely Cause
**Motherboard hardware failure** — one or more of:
1. Internal DC-DC converter failure (24V → 12V/5V/3.3V rails)
2. Chipset failure (Intel GM45)
3. CPU failure (Core 2 Duo P8400)
4. Failed component preventing main power-on sequence

### Not Yet Tested
- CMOS Profile switch position (try position 0)
- RAM reseat (SO-DIMM module)
- Boot with all peripherals removed
- Beep codes (no PC speaker connected)
- Multimeter measurements on internal voltage rails
