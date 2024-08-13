#include "ServoMotor.h"
#include "LineSensor.h"

#define LEFT_MOTOR_PIN 9
#define RIGHT_MOTOR_PIN 10

#define LEFT_LINE_SENSOR_PIN A0
#define RIGHT_LINE_SENSOR_PIN A1

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

  Serial.print("Left Line Detected: ");
  Serial.print(leftLineDetected);
  Serial.print(" | Right Line Detected: ");
  Serial.println(rightLineDetected);

  if (leftLineDetected && rightLineDetected) {
    leftMotor.setSpeed(180);
    rightMotor.setSpeed(180);
  } else if (leftLineDetected) {
    leftMotor.stop();
    rightMotor.setSpeed(180);
  } else if (rightLineDetected) {
    rightMotor.stop();
    leftMotor.setSpeed(180);
  } else {
    
    leftMotor.stop();
    rightMotor.stop();
  }

  delay(100);
}