#include "system.h"

#define LEFT_Wheel_PIN 9
#define RIGHT_Wheel_PIN 10
#define LEFT_LINE_SENSOR_PIN 12
#define RIGHT_LINE_SENSOR_PIN 13

system system(LEFT_Wheel_PIN, RIGHT_Wheel_PIN, LEFT_LINE_SENSOR_PIN, RIGHT_LINE_SENSOR_PIN);

void setup() {
  Serial.begin(9600);
  system.init();
}

void loop() {
  system.update();
  delay(100);
}