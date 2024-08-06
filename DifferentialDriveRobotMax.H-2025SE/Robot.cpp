#include "Robot.h"

Robot::Robot(int leftMotorPin, int rightMotorPin, int leftLineSensorPin, int rightLineSensorPin)
  : leftMotor(leftMotorPin), rightMotor(rightMotorPin),
    leftLineSensor(leftLineSensorPin), rightLineSensor(rightLineSensorPin) {}

void Robot::init() {
  leftMotor.attach();
  rightMotor.attach();
  leftLineSensor.init();
  rightLineSensor.init();
}

void Robot::moveForward() {
  leftMotor.setSpeed(180);
  rightMotor.setSpeed(0);
}

void Robot::turnLeft() {
  leftMotor.setSpeed(0);
  rightMotor.setSpeed(180);
}

void Robot::turnRight() {
  leftMotor.setSpeed(180);
  rightMotor.setSpeed(0);
}

void Robot::stop() {
  leftMotor.stop();
  rightMotor.stop();
}

void Robot::followLine() {
  int leftValue = leftLineSensor.readValue();
  int rightValue = rightLineSensor.readValue();
  
  if (leftValue < 500 && rightValue >= 500) {
    turnRight();
  } else if (rightValue < 500 && leftValue >= 500) {
    turnLeft();
  } else {
    moveForward();
  }
}