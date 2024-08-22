#include "LineSensor.h"
#include <Arduino.h>

LineSensor::LineSensor(int pin) : pin(pin) {}

void LineSensor::init() {
  pinMode(pin, INPUT);
}

bool LineSensor::isLineDetected() {
  return analogRead(pin) < 22;
  //if (analogRead(pin) > 22);
  //return false;
}
//bool LineSensor::noLineDetected(){
  //return analogRead(pin) > 40;
//}