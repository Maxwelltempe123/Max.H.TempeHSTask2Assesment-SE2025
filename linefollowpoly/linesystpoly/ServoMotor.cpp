#include "ServoMotor.h"

ServoMotor::ServoMotor(int motorPin, int motorDirection) : pin(motorPin), direction(motorDirection) {}

void ServoMotor::attach() {
    motor.attach(pin);
}

void ServoMotor::setSpeed(int speed) {
    int adjustedSpeed = (direction == 1) ? speed : -speed;
    motor.writeMicroseconds(1500 + adjustedSpeed);
}

void ServoMotor::stop() {
    motor.writeMicroseconds(1500);
}