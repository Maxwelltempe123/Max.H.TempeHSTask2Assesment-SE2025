#include "LineSystem.h"

#define LEFT_THRESHOLD 34
#define RIGHT_THRESHOLD 34
#define OFF_LINE_THRESHOLD 34

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

    if (leftSensor.isOnLine(LEFT_THRESHOLD) && rightSensor.isOnLine(RIGHT_THRESHOLD)) {
        // both sensors on the line (40 for left, 40 for right)
        leftMotor.setSpeed(1520);
        rightMotor.setSpeed(1480);
    } else if (leftValue > LEFT_THRESHOLD && rightValue == OFF_LINE_THRESHOLD) {
        // left sensor off the line (31), right sensor on the line (above 40)
        leftMotor.setSpeed(1520);
        rightMotor.setSpeed(1500);
    } else if (rightValue > RIGHT_THRESHOLD && leftValue == OFF_LINE_THRESHOLD) {
        // right sensor off the line (32), left sensor on the line (above 40)
        leftMotor.setSpeed(1500);
        rightMotor.setSpeed(1480);
    } else {
        // both sensors off the line or in other states
        leftMotor.stop();
        rightMotor.stop();
    }
}