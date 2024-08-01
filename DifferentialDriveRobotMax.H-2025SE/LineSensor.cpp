#include "LineSensor.h"
#include <Arduino.h>

LineSensor::LineSensor(int pin) : pin(pin) {}

void LineSensor::init() {
  pinMode(pin, INPUT);
}

int LineSensor::readValue() {
  return analogRead(pin);
}