#include "MechSystem.h"

MechSystem::MechSystem(int leftMotorPin, int rightMotorPin, int leftSensorPin, int leftThreshold, int rightSensorPin, int rightThreshold)
    : leftMotor(leftMotorPin), rightMotor(rightMotorPin), leftSensor(leftSensorPin, leftThreshold), rightSensor(rightSensorPin, rightThreshold) {}

void MechSystem::init() {
    leftMotor.attach();
    rightMotor.attach();
    leftSensor.init();
    rightSensor.init();
    ledArray.init();
}

void MechSystem::followLine() {
    bool leftDetected, rightDetected;
    updateSensorStates(leftDetected, rightDetected);

    if (leftDetected && rightDetected) {
        leftMotor.setSpeed(1800);
        rightMotor.setSpeed(1800);
        ledArray.displayHappyFace();
    } else if (leftDetected) {
        leftMotor.stop();
        rightMotor.setSpeed(1800);
        ledArray.displayLeftArrow();
    } else if (rightDetected) {
        rightMotor.stop();
        leftMotor.setSpeed(1800);
        ledArray.displayRightArrow();
    } else {
        leftMotor.stop();
        rightMotor.stop();
        ledArray.displaySadFace();
    }
}

void MechSystem::updateSensorStates(bool &leftDetected, bool &rightDetected) {
    leftDetected = leftSensor.isLineDetected();
    rightDetected = rightSensor.isLineDetected();
}