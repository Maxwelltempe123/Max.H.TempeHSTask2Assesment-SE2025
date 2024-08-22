#include "LineSensor.h"

LineSensor::LineSensor(int sensorPin) : pin(sensorPin) {}

int LineSensor::readValue() {
    return analogRead(pin);
}

bool LineSensor::isOnLine() {
    return readValue() < 40;  // Assuming the threshold for being on the line is below 40
}