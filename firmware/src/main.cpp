// Secure Autonomous Inspection Rover — ESP32 firmware
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
    Serial.printf("heartbeat %lu  uptime %lus\n", ++beatCount, now / 1000);
  }
}
