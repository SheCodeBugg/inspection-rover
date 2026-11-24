// Secure Autonomous Inspection Rover — main firmware (Arduino UNO R4 WiFi)
// Stage 0: "blink" + serial heartbeat to confirm the toolchain works.

#include <Arduino.h>
#include "config.h"

namespace {
unsigned long lastBeat = 0;
bool ledOn = false;
unsigned long beatCount = 0;
}  // namespace

void setup() {
  Serial.begin(115200);
  pinMode(PIN_STATUS_LED, OUTPUT);
  delay(500);
  Serial.println("Inspection rover booting...");
}

void loop() {
  const unsigned long now = millis();
  if (now - lastBeat >= HEARTBEAT_MS) {
    lastBeat = now;
    ledOn = !ledOn;
    digitalWrite(PIN_STATUS_LED, ledOn ? HIGH : LOW);
    beatCount++;
    Serial.print("heartbeat ");
    Serial.print(beatCount);
    Serial.print("  uptime ");
    Serial.print(now / 1000);
    Serial.println("s");
  }
}
