#include "LineSystem.h"

LineSystem::LineSystem()
    : leftMotor(9, 1), rightMotor(10, -1),
      leftSensor(A2), rightSensor(A3) {}

void LineSystem::setup() {
    leftMotor.attach();
    rightMotor.attach();
}

void LineSystem::loop() {
    followLine();
}

void LineSystem::followLine() {
    int leftValue = leftSensor.readValue();
    int rightValue = rightSensor.readValue();

    if (leftSensor.isOnLine() && rightSensor.isOnLine()) {
        // Both sensors on the line
        leftMotor.setSpeed(500);
        rightMotor.setSpeed(500);
    } else if (!leftSensor.isOnLine() && rightValue > 40) {
        // Left off the line, right on the line
        leftMotor.setSpeed(0);
        rightMotor.setSpeed(500);
    } else if (!rightSensor.isOnLine() && leftValue > 40) {
        // Right off the line, left on the line
        leftMotor.setSpeed(500);
        rightMotor.setSpeed(0);
    } else {
        // Both sensors off the line
        leftMotor.stop();
        rightMotor.stop();
    }
}