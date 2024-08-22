#include "LineSensor.h"

LineSensor::LineSensor(int sensorPin) : pin(sensorPin) {}

int LineSensor::readValue() {
    return analogRead(pin);
}

bool LineSensor::isOnLine(int threshold) {
    return readValue() > threshold;
}