#ifndef MECH_SYSTEM_H
#define MECH_SYSTEM_H

#include "ServoMotor.h"
#include "LineSensor.h"
#include "LedArray.h"

class MechSystem {
public:
    MechSystem(int leftMotorPin, int rightMotorPin, int leftSensorPin, int leftThreshold, int rightSensorPin, int rightThreshold);

    void init();

    void followLine();

private:
    ServoMotor leftMotor;
    ServoMotor rightMotor;
    LineSensor leftSensor;
    LineSensor rightSensor;
    LedArray ledArray;

    void updateSensorStates(bool &leftDetected, bool &rightDetected);
};

#endif