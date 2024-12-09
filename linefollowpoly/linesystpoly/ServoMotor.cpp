#include "ServoMotor.h"

//ServoMotor::ServoMotor(int motorPin, int motorDirection) : pin(motorPin), direction(motorDirection) {}
ServoMotor::ServoMotor(int motorPin) : pin(motorPin) {}

void ServoMotor::attach() {
    motor.attach(pin);
}

void ServoMotor::setSpeed(int speed) {
    //int adjustedSpeed = (direction == 1) ? speed : -speed;
    //motor.writeMicroseconds(1500 + adjustedSpeed);
    motor.writeMicroseconds(speed);
}

void ServoMotor::stop() {
    motor.writeMicroseconds(1500);
}