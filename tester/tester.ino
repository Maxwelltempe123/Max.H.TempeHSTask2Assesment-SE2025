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


 // if (leftLineDetected) {
    //Serial.println("Left detected");
  //}
  //else if (rightLineDetected) {
   // Serial.println("Right detected");
 // }
  //else if (leftLineDetected && rightLineDetected) {
   // Serial.println("Both detected following");
  //}
  //Serial.print("Left detected ");
  //Serial.print(leftLineDetected);
  //Serial.print("Right detected ");
  //Serial.println(rightLineDetected);

  if (leftLineDetected && rightLineDetected) {
    leftMotor.setSpeed(120);
    rightMotor.setSpeed(60);
    Serial.println("following line");
  } else if (leftLineDetected) {
    leftMotor.setSpeed(120);
    rightMotor.setSpeed(90);
    Serial.println("left turn");
  } else if (rightLineDetected) {
    rightMotor.setSpeed(90);
    leftMotor.setSpeed(120);
    Serial.println("right turn");
  } else {
    leftMotor.setSpeed(90);
    rightMotor.setSpeed(90);
    Serial.println("stop");
  }

  delay(1000);
}