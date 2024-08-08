#include "System.h"

System::System(int leftMotorPin, int rightMotorPin, int leftLineSensorPin, int rightLineSensorPin)
  : leftMotor(leftMotorPin), rightMotor(rightMotorPin),
    leftLineSensor(leftLineSensorPin), rightLineSensor(rightLineSensorPin) {}

void System::init() {
  leftMotor.attach();
  rightMotor.attach();
  leftLineSensor.init();
  rightLineSensor.init();
}

void System::moveForward() {
  leftMotor.setSpeed(180);
  rightMotor.setSpeed(180);
  delay(300)
}

void System::turnLeft() {
  leftMotor.setSpeed(0);
  rightMotor.setSpeed(180);
  delay(300)
}

void System::turnRight() {
  leftMotor.setSpeed(180);
  rightMotor.setSpeed(0);
  delay(300)
}

void System::stop() {
  leftMotor.stop();
  rightMotor.stop();
}

void System::followLine() {
  int leftValue = leftLineSensor.readValue();
  int rightValue = rightLineSensor.readValue();
  
  if (leftValue < 40 && rightValue >= 40) {
    turnRight();
  } else if (rightValue < 40 && leftValue >= 40) {
    turnLeft();
  } else {
    moveForward();
  }
}