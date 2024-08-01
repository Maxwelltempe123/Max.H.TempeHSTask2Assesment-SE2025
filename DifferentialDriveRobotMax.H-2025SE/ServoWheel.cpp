#include "ServoWheel.h"

ServoWheel::ServoWheel(int pin) : pin(pin) {}

void ServoWheel::Wheel() {
  wheel.attach(pin);
}

void ServoWheel::setSpeed(int speed) {
  wheel.write(speed);
}

void ServoWheel::stop() {
  wheel.write(90);
}