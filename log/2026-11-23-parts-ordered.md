# 2026-11-23 — Stage 1 parts ordered

**Stage:** 0 – Planning
**Time spent:** ~1.5 h (part research + ordering)

## What I did

- Inventoried my Arduino UNO R4 WiFi starter kit — it already covers the controller, ultrasonic sensor, IMU (GY-87), RFID reader, LEDs, breadboard and wires
- Decided to use the **UNO R4 WiFi** instead of buying an ESP32 for now
- Ordered (Amazon, arriving ~Nov 25): 2WD chassis kit, TB6612FNG motor driver 2-pack, LM393 speed sensor 5-pack, electrolytic capacitor kit
- Switched the firmware project to the UNO R4 WiFi and added test programs for the motors, encoders and ultrasonic sensor
- Wrote the Stage 1 pin map (`hardware/wiring/README.md`)

## Decisions

- **UNO R4 WiFi over ESP32:** already owned, 5 V logic works directly with the HC-SR04, has Wi-Fi. May add an ESP32 in Stage 4 if the security work needs it.
- **TB6612FNG over DRV8833:** matches the plan and tutorials; I can solder the headers myself.
- **Amazon chassis over Walmart:** same kit, ~$5 more, but Prime shipping, easy returns and a rated seller.

## Next

- Unbox and check parts when they arrive
- Solder headers onto one TB6612FNG
- Install VS Code + PlatformIO and run the blink test
- After finals: run `test_motors`, `test_encoders`, `test_ultrasonic`
