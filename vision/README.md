# Vision (Raspberry Pi) — Stage 3

Python + OpenCV code that runs on the Raspberry Pi to spot red or blinking warning LEDs on the mock racks and report them to the Arduino and dashboard.

Planned files:

- `detect_leds.py` — find red LEDs in a camera frame; detect blinking by comparing frames over ~2 s
- `link.py` — serial messages to and from the Arduino
- `requirements.txt` — Python packages

Setup (when Stage 3 starts):

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```
