// Motor test — TB6612FNG + 2 TT motors
//
// Prop the robot up so the wheels spin freely before running this!
//
// Sequence (repeats): left forward ramp, left backward, right forward ramp,
// right backward, both forward, spin in place, stop.
// Each step prints to the serial monitor so you can match what you see.
//
// Power: motors from the AA battery box -> TB6612 VM; Arduino 5V -> TB6612 VCC;
// all grounds connected; 470 uF capacitor across VM and GND (stripe to GND).

#include <Arduino.h>
#include "config.h"

namespace {

// speed: -255 (full reverse) .. 255 (full forward), 0 = stop
void setMotor(int pwmPin, int in1, int in2, int speed) {
  speed = constrain(speed, -255, 255);
  if (speed > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (speed < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else {
    digitalWrite(in1, LOW);  // both low = coast
    digitalWrite(in2, LOW);
  }
  analogWrite(pwmPin, abs(speed));
}

void left(int speed) {
  setMotor(PIN_MOTOR_A_PWM, PIN_MOTOR_A_IN1, PIN_MOTOR_A_IN2, speed);
}

void right(int speed) {
  setMotor(PIN_MOTOR_B_PWM, PIN_MOTOR_B_IN1, PIN_MOTOR_B_IN2, speed);
}

void stopAll() {
  left(0);
  right(0);
}

void step(const char* label, int l, int r, unsigned long ms) {
  Serial.println(label);
  left(l);
  right(r);
  delay(ms);
  stopAll();
  delay(500);
}

void ramp(const char* label, bool isLeft) {
  Serial.println(label);
  for (int s = 0; s <= 255; s += 15) {
    if (isLeft) left(s); else right(s);
    Serial.print("  speed ");
    Serial.println(s);
    delay(150);
  }
  stopAll();
  delay(500);
}

}  // namespace

void setup() {
  Serial.begin(115200);
  const int pins[] = {PIN_MOTOR_STBY,  PIN_MOTOR_A_PWM, PIN_MOTOR_A_IN1,
                      PIN_MOTOR_A_IN2, PIN_MOTOR_B_PWM, PIN_MOTOR_B_IN1,
                      PIN_MOTOR_B_IN2};
  for (int p : pins) pinMode(p, OUTPUT);
  digitalWrite(PIN_MOTOR_STBY, HIGH);  // take the driver out of standby
  stopAll();
  delay(2000);
  Serial.println("Motor test starting. Wheels should be off the ground.");
}

void loop() {
  ramp("LEFT forward ramp", true);
  step("LEFT backward", -180, 0, 1500);
  ramp("RIGHT forward ramp", false);
  step("RIGHT backward", 0, -180, 1500);
  step("BOTH forward", 180, 180, 2000);
  step("SPIN in place", 180, -180, 1500);
  Serial.println("STOP - pausing 3 s\n");
  delay(3000);
}

// Troubleshooting:
// - A wheel spins the wrong way: swap that motor's two wires on AO1/AO2 or BO1/BO2.
// - Nothing moves: check STBY is wired to D4, VM has battery power, grounds shared.
// - Arduino resets when motors start: power problem. Check the capacitor and
//   that the Arduino is NOT powered from the same AA pack.
