#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include <Servo.h>

class ServoMotor {
public:
    ServoMotor(int pin);

    void attach();
    void setSpeed(int microseconds);
    void stop();

private:
    int pin;
    Servo motor;
};

#endif