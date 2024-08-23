#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Servo.h>

class ServoMotor {
public:
    ServoMotor(int pin);
    void attach();
    void setSpeed(int speed); //speed in microseconds

private:
    int motorPin;
    Servo motor;
};

#endif
