#include "ServoMotor.h"
#include "LineSensor.h"
#include "LedArray.h"

#define LEFT_MOTOR_PIN 9
#define RIGHT_MOTOR_PIN 10

#define LEFT_LINE_SENSOR_PIN A2
#define RIGHT_LINE_SENSOR_PIN A3

ServoMotor leftMotor(LEFT_MOTOR_PIN);
ServoMotor rightMotor(RIGHT_MOTOR_PIN);

LineSensor leftSensor(LEFT_LINE_SENSOR_PIN);
LineSensor rightSensor(RIGHT_LINE_SENSOR_PIN);

void setup() {
  Serial.begin(9600);
  
  leftMotor.attach();
  rightMotor.attach();
  
  leftSensor.init();
  rightSensor.init();
}

void loop() {
  bool leftLineDetected = leftSensor.isLineDetected();
  bool rightLineDetected = rightSensor.isLineDetected();



  if (leftLineDetected && rightLineDetected) {
    leftMotor.setSpeed(1600);
    rightMotor.setSpeed(1450);
    Serial.println("following line");
  } else if (leftLineDetected) {
    leftMotor.setSpeed(1500);
    rightMotor.setSpeed(1450);
    Serial.println("left turn");
  } else if (rightLineDetected) {
    rightMotor.setSpeed(1500);
    leftMotor.setSpeed(1600);
    Serial.println("right turn");
  } else {
    leftMotor.setSpeed(1500);
    rightMotor.setSpeed(1500);
    Serial.println("stop");
  }

  delay(75);
}