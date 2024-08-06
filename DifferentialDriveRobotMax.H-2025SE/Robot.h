#ifndef ROBOT_H
#define ROBOT_H

#include "ServoMotor.h"
#include "LineSensor.h"

class Robot {
  private:
    ServoMotor leftMotor;
    ServoMotor rightMotor;
    LineSensor leftLineSensor;
    LineSensor rightLineSensor;
  
  public:
    Robot(int leftMotorPin, int rightMotorPin, int leftLineSensorPin, int rightLineSensorPin);
    void init();
    void moveForward();
    void turnLeft();
    void turnRight();
    void stop();
    void followLine();
};

#endif