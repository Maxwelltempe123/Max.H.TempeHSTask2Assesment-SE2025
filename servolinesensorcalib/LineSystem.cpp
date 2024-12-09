#include "LineSystem.h"

LineSystem::LineSystem(int leftMotorPin, int rightMotorPin, int leftSensorPin, int rightSensorPin) 
    : leftMotor(leftMotorPin), rightMotor(rightMotorPin), leftSensor(leftSensorPin), rightSensor(rightSensorPin) {
    lastLeftDetectedTime = 0;
    lastRightDetectedTime = 0;
    offLineThreshold = 500;  // threshold
}

void LineSystem::calibrateSensors() {
    Serial.println("Calibrating Left Sensor...");
    leftSensor.calibrate();
    delay(2000);
    Serial.println("Calibrating Right Sensor...");
    rightSensor.calibrate();
}

void LineSystem::adjustMotors() {
    bool leftOnLine = leftSensor.isOnLine();
    bool rightOnLine = rightSensor.isOnLine();

    unsigned long currentTime = millis();

    if (leftOnLine && !rightOnLine) {
        leftMotor.setSpeed(1500);  // stop
        rightMotor.setSpeed(1490);  // Forward
        lastLeftDetectedTime = currentTime;
    } else if (!leftOnLine && rightOnLine) {
        leftMotor.setSpeed(1600);  // forward
        rightMotor.setSpeed(1500);  // stop
        lastRightDetectedTime = currentTime;
    } else if (leftOnLine && rightOnLine) {
        leftMotor.setSpeed(1600);  // Forward
        rightMotor.setSpeed(1490);  // Forward
    } else {
        if ((currentTime - lastLeftDetectedTime > offLineThreshold) || 
            (currentTime - lastRightDetectedTime > offLineThreshold)) {
            leftMotor.setSpeed(1600);  // Adjust as necessary for correction
            rightMotor.setSpeed(1490); // Pivot or correct
        } else {
            leftMotor.setSpeed(1500);  // Stop
            rightMotor.setSpeed(1500); // Stop
        }
    }
}

void LineSystem::debugSensors() {
    leftSensor.debugReadings();
    rightSensor.debugReadings();
}
