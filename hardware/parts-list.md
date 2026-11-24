# Parts list

Prices are approximate (Nov 2026). Buy each stage's parts when that stage starts.

**Have** = already in my starter kit (Arduino UNO R4 WiFi kit) · **Ordered** = bought, waiting to arrive · **Buy later** = not needed yet

## Stage 1 — Driving robot

| Part | Purpose | Status | Cost |
| --- | --- | --- | --- |
| Arduino UNO R4 WiFi | Main controller (C++, has Wi-Fi) | Have | — |
| HC-SR04 ultrasonic module | Front obstacle distance | Have | — |
| 9G servo | Optional: sweep the ultrasonic sensor | Have | — |
| Breadboard + jumper wires (65 M/M, 20 F/M) | Prototyping | Have | — |
| Breadboard power module | Clean 5 V for sensors | Have | — |
| USB-C cable | Uploading code | Have | — |
| OLED screen, buzzer | Optional status display / alarm | Have | — |
| 2WD robot chassis kit (TT motors, encoder discs, 4×AA box) | Body, motors, wheels | Ordered (Amazon, YonPhsy) | $16.99 |
| TB6612FNG motor driver (2-pack, solder headers) | Controls both motors | Ordered | $5.99 |
| LM393 speed sensor modules (DAOKI 5-pack) | Read encoder discs for PID | Ordered | $8.29 |
| Electrolytic capacitor kit (ALLECIN 240 pcs, incl. 470 µF 16 V) | Stops brownout resets | Ordered | $9.99 |
| 4× AA batteries | Motor power | Buy | ~$5 |
| **Stage 1 total spent** | | | **~$46** |

## Stage 2 — Patrol and sensing

| Part | Purpose | Status | Cost |
| --- | --- | --- | --- |
| GY-87 10-DOF module (MPU-6050 IMU + compass) | Heading while patrolling | Have | — |
| MFRC522 RFID module + tag | Identify each rack | Have | — |
| Thermistor, DHT11 | Starter temperature sensing | Have | — |
| Extra RFID tags (pack) | One per rack | Buy later | ~$5 |
| Pololu Romi chassis + encoder pair kit | Upgraded chassis, better encoders | Buy later | ~$50 |
| IR line-sensor array (5–8 sensors) | Follow the aisle line | Buy later | $10–15 |
| MLX90614 IR thermometer | Non-contact temperature | Buy later | $18–20 |
| Rechargeable NiMH AAs + charger | Replace disposable AAs | Buy later | ~$20 |
| 5 V buck converter (3 A) | Run fully on battery (no power bank) | Buy later | ~$5 |

## Stage 3 — Camera and alerts

| Part | Purpose | Status | Cost |
| --- | --- | --- | --- |
| Red/green LEDs + resistors | Mock rack status lights | Have | — |
| Raspberry Pi 5 (1 GB or 2 GB) | Camera + vision | Buy later | $45–78 |
| Raspberry Pi Camera Module 3 | See warning LEDs | Buy later | ~$25 |
| 32 GB microSD | Pi OS | Buy later | ~$10 |
| 5 V 5 A UBEC | Power the Pi from the battery | Buy later | ~$10 |

## Stage 4 — Attack and secure

| Part | Purpose | Status | Cost |
| --- | --- | --- | --- |
| ESP32-S3 DevKitC (optional) | If the UNO R4 limits TLS / security work | Buy later if needed | ~$15 |
| USB Wi-Fi adapter with monitor mode (optional) | Traffic capture | Buy later | ~$20 |

## Tools

| Tool | Status |
| --- | --- |
| Soldering iron, solder | Have (I solder) |
| Multimeter | Check / buy (~$25) |
