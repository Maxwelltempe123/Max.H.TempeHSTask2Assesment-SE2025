#include "ServoMotor.h"

ServoMotor::ServoMotor(int pin) : pin(pin) {}

void ServoMotor::attach() {
    motor.attach(pin);
}

void ServoMotor::setSpeed(int microseconds) {
    motor.writeMicroseconds(microseconds);
}

void ServoMotor::stop() {
    motor.writeMicroseconds(1500);
}