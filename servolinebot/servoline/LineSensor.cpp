#include "LineSensor.h"
#include <Arduino.h>

LineSensor::LineSensor(int pin, int thresholdWhite, int thresholdBlack) 
    : sensorPin(pin), thresholdWhite(thresholdWhite), thresholdBlack(thresholdBlack) {}

int LineSensor::readValue() {
    return analogRead(sensorPin);
}

bool LineSensor::isOnLine() {
    int value = readValue();
    return value >= thresholdBlack;
}

bool LineSensor::isOnWhite() {
    int value = readValue();
    return value <= thresholdWhite;
}
