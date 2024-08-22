#ifndef LINESYSTEM_H
#define LINESYSTEM_H

#include "ServoMotor.h"
#include "LineSensor.h"
#include "System.h"

class LineSystem : public System {
private:
    ServoMotor leftMotor;
    ServoMotor rightMotor;
    LineSensor leftSensor;
    LineSensor rightSensor;

public:
    LineSystem();
    void setup() override;
    void loop() override;
    void followLine();
};

#endif