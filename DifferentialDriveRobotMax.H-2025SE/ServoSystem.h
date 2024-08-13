#ifndef SYSTEM_H
#define SYSTEM_H

#include "ServoMotor.h"
#include "LineSensor.h"

class System {
  private:
    ServoMotor leftMotor;
    ServoMotor rightMotor;
    LineSensor leftLineSensor;
    LineSensor rightLineSensor;
  
  public:
    System(int leftMotorPin, int rightMotorPin, int leftLineSensorPin, int rightLineSensorPin);
    void init();
    void moveForward();
    void turnLeft();
    void turnRight();
    void stop();
    void followLine();
};

#endif