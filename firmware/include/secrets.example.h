#pragma once

// Copy this file to secrets.h and fill in real values.
// secrets.h is listed in .gitignore so it never reaches GitHub.
//
// Stage 4 note: hard-coded secrets in firmware are a real weakness.
// In v2, keys move out of the source code and into protected storage.

constexpr char WIFI_SSID[] = "your-hotspot-name";
constexpr char WIFI_PASSWORD[] = "your-hotspot-password";

constexpr char MQTT_HOST[] = "192.168.0.10";
constexpr int MQTT_PORT = 1883;  // 8883 once TLS is on (Stage 4)
