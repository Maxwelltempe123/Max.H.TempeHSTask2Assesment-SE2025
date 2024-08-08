#include "ServoMotor.h"

ServoMotor::ServoMotor(int pin) : pin(pin) {}

void ServoMotor::attach() {
  motor.attach(pin);
}

void ServoMotor::setSpeed(int speed) {
  motor.write(speed);
}

void ServoMotor::stop() {
  motor.write(90); 
}