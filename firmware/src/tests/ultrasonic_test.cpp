// Ultrasonic test — HC-SR04
//
// Wiring: VCC -> 5V, GND -> GND, Trig -> D11, Echo -> D12.
// Move your hand toward and away from the sensor; distance should track it.
// Check accuracy against a ruler at 10, 30 and 100 cm and log the results.

#include <Arduino.h>
#include "config.h"

namespace {
constexpr unsigned long ECHO_TIMEOUT_US = 30000;  // ~5 m round trip; beyond = no echo

// Returns distance in cm, or -1 if nothing was detected in range.
float readDistanceCm() {
  digitalWrite(PIN_ULTRASONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_ULTRASONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_ULTRASONIC_TRIG, LOW);

  const unsigned long duration = pulseIn(PIN_ULTRASONIC_ECHO, HIGH, ECHO_TIMEOUT_US);
  if (duration == 0) return -1.0f;
  // Sound travels ~0.0343 cm/us; divide by 2 for the round trip.
  return duration * 0.0343f / 2.0f;
}
}  // namespace

void setup() {
  Serial.begin(115200);
  pinMode(PIN_ULTRASONIC_TRIG, OUTPUT);
  pinMode(PIN_ULTRASONIC_ECHO, INPUT);
  delay(1000);
  Serial.println("Ultrasonic test. Move your hand in front of the sensor.");
}

void loop() {
  const float cm = readDistanceCm();
  if (cm < 0) {
    Serial.println("no echo (nothing in range)");
  } else {
    Serial.print(cm, 1);
    Serial.println(" cm");
  }
  delay(200);  // HC-SR04 needs ~60 ms between pings; 200 ms keeps output readable
}
