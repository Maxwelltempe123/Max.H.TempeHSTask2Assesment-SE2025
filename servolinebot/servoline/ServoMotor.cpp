#include "ServoMotor.h"

ServoMotor::ServoMotor(int pin) : motorPin(pin) {}

void ServoMotor::attach() {
    motor.attach(motorPin);
}

void ServoMotor::setSpeed(int speed) {
    motor.writeMicroseconds(speed);
}
