#include "LineSensor.h"
#include <Arduino.h>

LineSensor::LineSensor(int pin) : pin(pin) {}

void LineSensor::init() {
  pinMode(pin, INPUT);
}

bool LineSensor::isLineDetected() {
  return digitalRead(pin) == HIGH;
}