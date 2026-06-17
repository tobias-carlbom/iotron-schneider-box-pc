# Network Configuration

## Network Interfaces

The system uses three Ethernet connections plus one COM port:

| Interface | Purpose | Subnet |
|-----------|---------|--------|
| ETH1 (onboard) | Machine / junction box network | 192.168.0.x |
| ETH2 (onboard) | Camera network (GigE Vision) | 192.168.3.x |
| Intel D33025 (PCIe) | Factory / plant network | Routed via 192.168.0.146 |
| COM1 | WAGO PLC / serial devices | RS-232 |

## Static IP Addresses

From `StaticIpAddressUsed.ini`:

| Device | IP Address | Description |
|--------|------------|-------------|
| Junction Box | 192.168.0.147 | "PC cassetta" — machine control interface |
| Camera | 192.168.3.101 | JAI GigE Vision camera |

## Routing Table

From `MBEthNetStart.cmd` (applied at startup):

```
route add 10.202.71.0  mask 255.255.255.0  192.168.0.146
route add 192.168.20.0 mask 255.255.255.0  192.168.0.146
route add 192.168.1.0  mask 255.255.255.0  192.168.0.146
```

Gateway 192.168.0.146 provides access to:
- **10.202.71.0/24** — Factory/plant network
- **192.168.20.0/24** — Secondary network segment
- **192.168.1.0/24** — Additional network segment

## Moxa NE-4110

Serial device server for COM-over-Ethernet. Configuration in `E:\Grafikscan3000\MoxaNe4110\`:
- `ComMapping.ini` — COM port mapping
- `ConfigIni.txt` — Device configuration

## Network Startup Scripts

| Script | Location | Action |
|--------|----------|--------|
| MBEthNetStart.cmd | Console\Eseguibile\ | Adds static routes |
| NetStart.cmd | Console\Eseguibile\ | Basic network start |
| NetStop.cmd | Console\Eseguibile\ | Network stop |
| BielloniNetStart.cmd | Console\Eseguibile\ | Machine-specific network config |

## Remote Access Ports

| Service | Default Port |
|---------|-------------|
| UltraVNC | 5900 (VNC) |
| OpenVPN | 1194 (UDP) |
| TeamViewer | Outbound HTTPS |
| CoDeSys Web Server | 8080 (licensed) |
