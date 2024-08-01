#ifndef SYSTEM_H
#define SYSTEM_H

#include "ServoWheel.h"
#include "LineSensor.h"

class System {
  private:
    ServoWheel leftMotor;
    ServoWheel rightMotor;
    LineSensor leftLineSensor;
    LineSensor rightLineSensor;
  
  public:
    System(int leftWheelPin, int rightWheelPin, int leftLineSensorPin, int rightLineSensorPin);
    void init();
    void moveForward();
    void turnLeft();
    void turnRight();
    void stop();
    void followLine();
    void update();
};

#endif