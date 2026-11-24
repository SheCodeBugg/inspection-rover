#pragma once

// Pin assignments and tunable settings live here so the rest of the
// code never hard-codes a pin number. Update as parts are wired.

// --- Status LED ---
// Many ESP32-S3 DevKitC boards use an addressable RGB LED on GPIO 48;
// if yours doesn't blink, wire a regular LED + 220 ohm resistor to this pin.
constexpr int PIN_STATUS_LED = 2;

// --- Motor driver (TB6612FNG) --- Stage 1
constexpr int PIN_MOTOR_STBY = -1;  // TODO: assign when wiring
constexpr int PIN_MOTOR_A_PWM = -1;
constexpr int PIN_MOTOR_A_IN1 = -1;
constexpr int PIN_MOTOR_A_IN2 = -1;
constexpr int PIN_MOTOR_B_PWM = -1;
constexpr int PIN_MOTOR_B_IN1 = -1;
constexpr int PIN_MOTOR_B_IN2 = -1;

// --- Wheel encoders --- Stage 1
constexpr int PIN_ENCODER_LEFT = -1;
constexpr int PIN_ENCODER_RIGHT = -1;

// --- I2C bus (distance sensor, IMU, IR thermometer) ---
constexpr int PIN_I2C_SDA = -1;
constexpr int PIN_I2C_SCL = -1;

// --- Timing ---
constexpr unsigned long HEARTBEAT_MS = 1000;
