#include "ServoMotor.h"

ServoMotor::ServoMotor(int pin) : pin(pin) {}

void ServoMotor::attach() {
  motor.attach(pin);
}

void ServoMotor::setSpeed(int speed) {
  motor.writeMicroseconds(speed);
}

