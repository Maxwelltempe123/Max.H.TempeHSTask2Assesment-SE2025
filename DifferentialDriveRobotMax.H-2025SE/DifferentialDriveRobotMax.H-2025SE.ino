#include "MechSystem.h"

#define LEFT_MOTOR_PIN 9
#define RIGHT_MOTOR_PIN 10
#define LEFT_LINE_SENSOR_PIN A2
#define RIGHT_LINE_SENSOR_PIN A3

#define LEFT_SENSOR_THRESHOLD 36
#define RIGHT_SENSOR_THRESHOLD 36

MechSystem system(LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN, LEFT_LINE_SENSOR_PIN, LEFT_SENSOR_THRESHOLD, RIGHT_LINE_SENSOR_PIN, RIGHT_SENSOR_THRESHOLD);

void setup() {
    Serial.begin(9600);
    system.init(); 
    Serial.println("System Initialized");
}

void loop() {
    system.followLine();
    delay(100);
}