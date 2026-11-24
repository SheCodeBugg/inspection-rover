# Dashboard and alerts — Stage 2–3

Shows each rack's latest temperature and fault status, and sends phone alerts.

Plan:

- MQTT broker: [Mosquitto](https://mosquitto.org/) running on a laptop on the rover's private hotspot
- Dashboard: Node-RED or a small web page subscribed to `rover/racks/#`
- Phone alerts: ntfy or a Telegram bot when a fault is detected

Planned MQTT topics:

| Topic | Payload | From |
| --- | --- | --- |
| `rover/status` | position, battery, mode | ESP32 |
| `rover/racks/<id>/temp` | temperature °C | ESP32 |
| `rover/racks/<id>/fault` | `red` / `blinking` / `ok` | Pi |
| `rover/cmd` | `start`, `stop`, `home` | dashboard |
