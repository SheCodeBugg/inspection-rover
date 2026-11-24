# System diagram

```mermaid
flowchart LR
    S[Sensors<br/>distance, line, RFID, temp] -->|I2C / GPIO| E[Arduino UNO R4 WiFi<br/>drive, sense, Wi-Fi]
    C[Camera] -->|CSI ribbon| P[Raspberry Pi<br/>OpenCV vision]
    E <-->|serial UART| P
    E -->|PWM| M[Motor driver<br/>TB6612FNG] --> W[Motors + encoders]
    W -->|encoder pulses| E
    E -->|Wi-Fi / MQTT| N[Wi-Fi network<br/>private hotspot]
    P -->|Wi-Fi / MQTT| N
    N --> D[Dashboard + phone alerts]
    B[Power system<br/>battery, regulators] -.-> E
    B -.-> P
    B -.-> M
```

## Parts by stage

| Stage | Adds to the diagram |
| --- | --- |
| 1 | Arduino UNO R4 WiFi, TB6612FNG motor driver, motors + LM393 encoders, HC-SR04, power |
| 2 | GY-87 IMU, line sensors, RFID, IR thermometer, Wi-Fi/MQTT, dashboard |
| 3 | Raspberry Pi, camera, phone alerts |
| 4 | TLS + message authentication on every network link (ESP32-S3 added only if the UNO R4 can't handle it) |
