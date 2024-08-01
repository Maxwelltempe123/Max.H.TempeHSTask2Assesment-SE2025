#include "System.h"

system::system(int leftWheelPin, int rightWheelPin, int trigPin, int echoPin, int leftLineSensorPin, int centerLineSensorPin, int rightLineSensorPin)
  : leftWheel(leftWheelPin), rightWheel(rightWheelPin), leftLineSensor(leftLineSensorPin), rightLineSensor(rightLineSensorPin) {}

void system::init() {
  leftWheel.attach();
  rightWheel.attach();
  leftLineSensor.init();
  rightLineSensor.init();
}

void system::moveForward() {
  leftWheel.setSpeed(180);
  rightWheel.setSpeed(0);
}

void system::turnLeft() {
  leftWheel.setSpeed(0);
  rightWheel.setSpeed(180);
}

void system::turnRight() {
  leftWheel.setSpeed(180);
  rightWheel.setSpeed(0);
}

void system::stop() {
  leftWheel.stop();
  rightWheel.stop();
}

void system::followLine() {
  int leftValue = leftLineSensor.readValue();
  int rightValue = rightLineSensor.readValue();

  if (leftValue < 500) {
    turnLeft();
  }
  elif (rightValue < 500) {
    turnRight();
  }
  else {
    stop();
  }


void system::update() {
  followLine();
}