# Wiring diagrams

Put wiring diagrams here (Fritzing `.fzz` or KiCad files, plus a PNG export so they show on GitHub).

Naming: `stage1-motors-power.png`, `stage2-sensors.png`, etc.

Power rules (Stage 1 lesson):

- Motors and logic get **separate regulated supplies**
- **All grounds connected** together
- Large capacitor (e.g. 470 µF) across the motor driver's supply
- If the ESP32 randomly resets, check power before code
