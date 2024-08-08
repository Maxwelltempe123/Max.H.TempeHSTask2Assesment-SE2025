#include "System.h"

#define LEFT_MOTOR_PIN 10
#define RIGHT_MOTOR_PIN 9
#define LEFT_LINE_SENSOR_PIN A5
#define RIGHT_LINE_SENSOR_PIN A4     

System system(LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN, LEFT_LINE_SENSOR_PIN, RIGHT_LINE_SENSOR_PIN);

void setup() {
  Serial.begin(9600);
  system.init();
}

void loop() {
  system.followLine();
  delay(100);
}