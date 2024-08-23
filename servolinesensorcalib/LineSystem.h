#ifndef LINESYSTEM_H
#define LINESYSTEM_H

#include "ServoMotor.h"
#include "LineSensor.h"

class LineSystem {
private:
    ServoMotor leftMotor;
    ServoMotor rightMotor;
    LineSensor leftSensor;
    LineSensor rightSensor;
    unsigned long lastLeftDetectedTime;
    unsigned long lastRightDetectedTime;
    unsigned long offLineThreshold;

public:
    LineSystem(int leftMotorPin, int rightMotorPin, int leftSensorPin, int rightSensorPin);
    void calibrateSensors();
    void adjustMotors();
    void debugSensors();  // To monitor the sensor values
};

#endif
