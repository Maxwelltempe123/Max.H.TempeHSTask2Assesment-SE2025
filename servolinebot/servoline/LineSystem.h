#ifndef LINESYSTEM_H
#define LINESYSTEM_H

#include "ServoMotor.h"
#include "LineSensor.h"

class LineSystem {
public:
    LineSystem(int leftMotorPin, int rightMotorPin, int leftSensorPin, int rightSensorPin);
    void setup();
    void followLine();

private:
    ServoMotor leftMotor;
    ServoMotor rightMotor;
    LineSensor leftSensor;
    LineSensor rightSensor;
    unsigned long lastLeftDetectedTime;
    unsigned long lastRightDetectedTime;
    const unsigned long offLineThreshold = 500; 

    void adjustMotors();
};

#endif