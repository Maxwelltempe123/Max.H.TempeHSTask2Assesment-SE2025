#include "Robot.h"

// Define pins
#define LEFT_MOTOR_PIN 9
#define RIGHT_MOTOR_PIN 10
#define LEFT_LINE_SENSOR_PIN A0
#define RIGHT_LINE_SENSOR_PIN A1

Robot robot(LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN, LEFT_LINE_SENSOR_PIN, RIGHT_LINE_SENSOR_PIN);

void setup() {
  Serial.begin(9600);
  robot.init();
}

void loop() {
  robot.followLine();
  delay(100);
}