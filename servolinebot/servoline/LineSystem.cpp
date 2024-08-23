#include "LineSystem.h"
#include <Arduino.h>

LineSystem::LineSystem(int leftMotorPin, int rightMotorPin, int leftSensorPin, int rightSensorPin)
    : leftMotor(leftMotorPin), rightMotor(rightMotorPin),
      leftSensor(leftSensorPin, 30, 40), rightSensor(rightSensorPin, 30, 40),
      lastLeftDetectedTime(0), lastRightDetectedTime(0) {}

void LineSystem::setup() {
    Serial.begin(9600);
    leftMotor.attach();
    rightMotor.attach();
}

void LineSystem::followLine() {
    adjustMotors();
}

void LineSystem::adjustMotors() {
    bool leftOnLine = leftSensor.isOnLine();
    bool rightOnLine = rightSensor.isOnLine();

    Serial.print("Left On Line: ");
    Serial.println(leftOnLine);
    Serial.print("Right On Line: ");
    Serial.println(rightOnLine);

    unsigned long currentTime = millis();

    if (leftOnLine) {
        lastLeftDetectedTime = currentTime;
    }
    if (rightOnLine) {
        lastRightDetectedTime = currentTime;
    }

    if (leftOnLine && !rightOnLine) {
        Serial.println("Pivoting Right");
        leftMotor.setSpeed(1520);
        rightMotor.setSpeed(1460);
    } else if (!leftOnLine && rightOnLine) {
        Serial.println("Pivoting Left");
        leftMotor.setSpeed(1600);
        rightMotor.setSpeed(1480);
    } else if (leftOnLine && rightOnLine) {
        Serial.println("Moving Straight");
        leftMotor.setSpeed(1520);
        rightMotor.setSpeed(1460);
    } else {
        Serial.println("Off Line, Correcting");
        if ((currentTime - lastLeftDetectedTime > offLineThreshold) || 
            (currentTime - lastRightDetectedTime > offLineThreshold)) {
            leftMotor.setSpeed(1600);
            rightMotor.setSpeed(1400);
        } else {
            Serial.println("Stopping");
            leftMotor.setSpeed(1500);
            rightMotor.setSpeed(1500);
        }
    }
}