#include "ServoMotor.h"
#include "LineSensor.h"
//#include "LedArray.h"
#include <Arduino.h>

#define LEFT_MOTOR_PIN 9
#define RIGHT_MOTOR_PIN 10

#define LEFT_LINE_SENSOR_PIN A2
#define RIGHT_LINE_SENSOR_PIN A3

ServoMotor leftMotor(LEFT_MOTOR_PIN);
ServoMotor rightMotor(RIGHT_MOTOR_PIN);

LineSensor leftSensor(LEFT_LINE_SENSOR_PIN);
LineSensor rightSensor(RIGHT_LINE_SENSOR_PIN);

//LedArray ledArray;

void setup() {
  Serial.begin(9600);
  
  leftMotor.attach();
  rightMotor.attach();
  
  leftSensor.init();
  rightSensor.init();

  //ledArray.init();
}

void loop() {
  bool leftLineDetected = leftSensor.isLineDetected();
  bool rightLineDetected = rightSensor.isLineDetected();

  Serial.print("Left Line Detected: ");
  Serial.println(leftLineDetected);
  Serial.print("Right Line Detected: ");
  Serial.println(rightLineDetected);


  if (leftLineDetected && rightLineDetected) {
    leftMotor.setSpeed(1600);
    rightMotor.setSpeed(1450);
    //ledArray.displayHappyFace();
  } else if (leftLineDetected) {
    leftMotor.setSpeed(1500);
    rightMotor.setSpeed(1450);
    //ledArray.displayLeftArrow();
  } else if (rightLineDetected) {
    rightMotor.setSpeed(1500);
    leftMotor.setSpeed(1600);
    //ledArray.displayRightArrow();
  } else {
    leftMotor.setSpeed(1500);
    rightMotor.setSpeed(1500);
    //ledArray.displaySadFace();
  }

  delay(100);
}