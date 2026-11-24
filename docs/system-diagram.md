# System diagram

```mermaid
flowchart LR
    S[Sensors<br/>distance, line, RFID, temp] -->|I2C / GPIO| E[ESP32<br/>drive, sense, Wi-Fi]
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
| 1 | ESP32, motor driver, motors + encoders, distance sensors, IMU, power |
| 2 | Line sensors, RFID, IR thermometer, Wi-Fi/MQTT, dashboard |
| 3 | Raspberry Pi, camera, phone alerts |
| 4 | TLS + message authentication on every network link |
