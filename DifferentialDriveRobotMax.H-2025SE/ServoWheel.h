#ifndef SERVOWHEEL_H
#define SERVOWHEEL_H

#include <Servo.h>

class ServoWheel {
  private:
    Servo wheel;
    int pin;
  
  public:
    ServoWheel() {}
    ServoWheel(int pin);
    void attach();
    void setSpeed(int speed);
    void stop();
};

#endif