#include "LineSystem.h"
#include <Arduino.h>

LineSystem::LineSystem(int leftMotorPin, int rightMotorPin, int leftSensorPin, int rightSensorPin)
    : leftMotor(leftMotorPin), rightMotor(rightMotorPin),
      leftSensor(leftSensorPin, 30, 46), rightSensor(rightSensorPin, 28, 46),
      lastLeftDetectedTime(0), lastRightDetectedTime(0) {}

void LineSystem::setup() {
    leftMotor.attach();
    rightMotor.attach();
}

void LineSystem::followLine() {
    adjustMotors();
}

void LineSystem::adjustMotors() {
    bool leftOnLine = leftSensor.isOnLine();
    bool rightOnLine = rightSensor.isOnLine();

    unsigned long currentTime = millis();

    if (leftOnLine) {
        lastLeftDetectedTime = currentTime;
    }
    if (rightOnLine) {
        lastRightDetectedTime = currentTime;
    }

    if (leftOnLine && !rightOnLine) {
        leftMotor.setSpeed(1520);  // Forward
        rightMotor.setSpeed(1400); // Pivot right
    } else if (!leftOnLine && rightOnLine) {
        leftMotor.setSpeed(1600);  // Pivot left
        rightMotor.setSpeed(1480); // Forward
    } else if (leftOnLine && rightOnLine) {
        leftMotor.setSpeed(1520);  // Move straight
        rightMotor.setSpeed(1480); // Move straight
    } else {
        // If off the line for too long, refresh
        if ((currentTime - lastLeftDetectedTime > offLineThreshold) || 
            (currentTime - lastRightDetectedTime > offLineThreshold)) {
            leftMotor.setSpeed(1600);  // Pivot left
            rightMotor.setSpeed(1400); // Pivot right
        } else {
            leftMotor.setSpeed(1500);  // Stop
            rightMotor.setSpeed(1500); // Stop
        }
    }
}
