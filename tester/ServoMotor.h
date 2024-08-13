#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Servo.h>

class ServoMotor {
  private:
    Servo motor;
    int pin;
  
  public:
    ServoMotor(int pin);
    void attach();
    void setSpeed(int speed);
};

#endif