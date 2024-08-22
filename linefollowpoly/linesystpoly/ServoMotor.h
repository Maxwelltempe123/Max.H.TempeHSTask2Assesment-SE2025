#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Servo.h>

class ServoMotor {
private:
    Servo motor;
    int pin;
    //int direction;

public:
    //ServoMotor(int motorPin, int motorDirection);
    ServoMotor(int motorPin);
    void attach();
    void setSpeed(int speed);
    void stop();
};

#endif