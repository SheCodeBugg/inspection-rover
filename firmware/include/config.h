#pragma once

// Pin assignments and tunable settings for the Arduino UNO R4 WiFi.
// Every program includes this file, so a wire only ever moves in one place.
// Full wiring table: hardware/wiring/README.md

// --- Status LED ---
constexpr int PIN_STATUS_LED = LED_BUILTIN;  // D13

// --- Wheel encoders (LM393 speed sensors, D0/OUT pin) --- Stage 1
// D2 and D3 support interrupts, so no pulses are missed.
constexpr int PIN_ENCODER_LEFT = 2;
constexpr int PIN_ENCODER_RIGHT = 3;
constexpr int ENCODER_SLOTS = 20;  // slots in the chassis kit's encoder disc

// --- Motor driver (TB6612FNG) --- Stage 1
// PWMA/PWMB must be PWM pins (~3, 5, 6, 9, 10, 11 on the UNO R4).
constexpr int PIN_MOTOR_STBY = 4;
constexpr int PIN_MOTOR_A_PWM = 5;   // left motor speed
constexpr int PIN_MOTOR_A_IN1 = 7;
constexpr int PIN_MOTOR_A_IN2 = 8;
constexpr int PIN_MOTOR_B_PWM = 6;   // right motor speed
constexpr int PIN_MOTOR_B_IN1 = 9;
constexpr int PIN_MOTOR_B_IN2 = 10;

// --- Ultrasonic distance sensor (HC-SR04) --- Stage 1
constexpr int PIN_ULTRASONIC_TRIG = 11;
constexpr int PIN_ULTRASONIC_ECHO = 12;

// --- Optional servo to sweep the ultrasonic sensor ---
constexpr int PIN_SERVO = A1;

// --- I2C bus (GY-87 IMU, OLED) uses the dedicated SDA/SCL pins ---

// --- Timing ---
constexpr unsigned long HEARTBEAT_MS = 1000;
