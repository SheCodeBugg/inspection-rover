// Encoder test — 2 LM393 speed sensors reading the slotted encoder discs
//
// Wiring per sensor: VCC -> 5V, GND -> GND, D0 (or OUT) -> D2 (left) / D3 (right).
// Ignore the A0 pin on the sensor.
//
// Turn each wheel slowly by hand. Counts should rise by ENCODER_SLOTS (20)
// per full wheel turn. The sensor's small LED blinks as each slot passes.

#include <Arduino.h>
#include "config.h"

namespace {
volatile unsigned long leftCount = 0;
volatile unsigned long rightCount = 0;
volatile unsigned long lastLeftUs = 0;
volatile unsigned long lastRightUs = 0;

// Ignore edges closer than this — cheap sensors can "chatter" on one slot.
constexpr unsigned long DEBOUNCE_US = 800;

void onLeft() {
  const unsigned long now = micros();
  if (now - lastLeftUs > DEBOUNCE_US) {
    leftCount++;
    lastLeftUs = now;
  }
}

void onRight() {
  const unsigned long now = micros();
  if (now - lastRightUs > DEBOUNCE_US) {
    rightCount++;
    lastRightUs = now;
  }
}
}  // namespace

void setup() {
  Serial.begin(115200);
  pinMode(PIN_ENCODER_LEFT, INPUT);
  pinMode(PIN_ENCODER_RIGHT, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_LEFT), onLeft, RISING);
  attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_RIGHT), onRight, RISING);
  delay(1000);
  Serial.println("Encoder test. Turn the wheels by hand.");
}

void loop() {
  noInterrupts();
  const unsigned long l = leftCount;
  const unsigned long r = rightCount;
  interrupts();

  Serial.print("left: ");
  Serial.print(l);
  Serial.print(" (");
  Serial.print(static_cast<float>(l) / ENCODER_SLOTS, 2);
  Serial.print(" turns)   right: ");
  Serial.print(r);
  Serial.print(" (");
  Serial.print(static_cast<float>(r) / ENCODER_SLOTS, 2);
  Serial.println(" turns)");
  delay(500);
}

// Troubleshooting:
// - Count never changes: is the disc actually passing through the sensor's slot?
//   Does the sensor's LED blink when you block the slot with paper?
// - Count jumps by 2+ per slot: raise DEBOUNCE_US, or try FALLING instead of RISING.
