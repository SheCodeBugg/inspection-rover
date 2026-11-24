# Threat model (Stage 4)

> **Ethics:** all testing happens only on my own rover, on my own private network.

## What's worth protecting

- Control of the rover (drive, stop, route)
- Accuracy of fault reports (an attacker could hide a real fault or fake one)
- Wi-Fi and MQTT credentials

## Attack surface

| Entry point | v1 weakness (expected) | v2 defense (planned) |
| --- | --- | --- |
| MQTT over Wi-Fi | Plain text — anyone on the network can read and send messages | TLS encryption (mbedTLS) |
| `rover/cmd` topic | No check of who sent a command (spoofing) | HMAC message authentication with a shared key |
| Captured commands | Can be re-sent later (replay) | Message counter / timestamp; reject old or repeated ones |
| Firmware secrets | Wi-Fi/MQTT credentials in plain text | Encrypted NVS storage; flash encryption |
| ESP32 ↔ Pi serial link | Physical access only | Out of scope (physical security) |

## Attack log

| Date | Attack | Target version | Result | Notes |
| --- | --- | --- | --- | --- |
| | | | | |
