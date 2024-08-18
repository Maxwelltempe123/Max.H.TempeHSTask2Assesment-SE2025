#include "LineSensor.h"
#include <Arduino.h>

LineSensor::LineSensor(int pin, int threshold) : pin(pin), threshold(threshold) {}

void LineSensor::init() {
    pinMode(pin, INPUT);
}

bool LineSensor::isLineDetected() {
    int sensorValue = analogRead(pin);
    return sensorValue < threshold; 
}