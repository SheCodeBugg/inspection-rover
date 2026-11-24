# Wiring

Put wiring diagrams here (Fritzing `.fzz` or KiCad files, plus a PNG export so they show on GitHub). Naming: `stage1-motors-power.png`, `stage2-sensors.png`, etc.

## Stage 1 pin map — Arduino UNO R4 WiFi

Matches `firmware/include/config.h`. If a wire moves, change both.

| Part | Part pin | Arduino pin | Notes |
| --- | --- | --- | --- |
| TB6612FNG | VCC | 5V | Logic power |
| TB6612FNG | GND | GND | Shared ground |
| TB6612FNG | VM | AA battery box + | Motor power (4×AA ≈ 6 V) |
| TB6612FNG | STBY | D4 | HIGH = driver on |
| TB6612FNG | PWMA | D5 | Left motor speed (PWM) |
| TB6612FNG | AIN1 / AIN2 | D7 / D8 | Left motor direction |
| TB6612FNG | PWMB | D6 | Right motor speed (PWM) |
| TB6612FNG | BIN1 / BIN2 | D9 / D10 | Right motor direction |
| TB6612FNG | AO1 / AO2 | Left motor wires | Swap if it spins backward |
| TB6612FNG | BO1 / BO2 | Right motor wires | Swap if it spins backward |
| LM393 (left) | VCC / GND / D0 | 5V / GND / D2 | Interrupt pin |
| LM393 (right) | VCC / GND / D0 | 5V / GND / D3 | Interrupt pin |
| HC-SR04 | VCC / GND | 5V / GND | |
| HC-SR04 | Trig / Echo | D11 / D12 | |
| Servo (optional) | Signal | A1 | Sweeps the HC-SR04 |
| 470 µF capacitor | + / − | VM / GND at the driver | Stripe side = − (GND) |

## Power rules (Stage 1 lesson)

- **Motors** run from the AA battery box (TB6612 VM). **Arduino** runs from USB or a power bank — never from the motor pack while testing.
- **All grounds connected**: Arduino GND, TB6612 GND, battery box −.
- 470 µF capacitor across VM and GND, close to the driver. Check polarity before powering on.
- If the Arduino randomly resets, check power before code.
