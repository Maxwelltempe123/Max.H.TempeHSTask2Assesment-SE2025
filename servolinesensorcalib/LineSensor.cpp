#include "LineSensor.h"

LineSensor::LineSensor(int sensorPin) {
    pin = sensorPin;
    thresholdLow = 0;  // Initialize with default values
    thresholdHigh = 1023;
}

void LineSensor::calibrate() {
    int whiteValue = analogRead(pin);
    delay(2000);  // Time to manually place sensor on black surface
    int blackValue = analogRead(pin);
    
    thresholdLow = whiteValue + (blackValue - whiteValue) / 4;  // Expand the range
    thresholdHigh = blackValue - (blackValue - whiteValue) / 4;
}

bool LineSensor::isOnLine() {
    int sensorValue = analogRead(pin);
    return sensorValue >= thresholdLow && sensorValue <= thresholdHigh;
}

int LineSensor::readValue() {
    return analogRead(pin);
}

void LineSensor::debugReadings() {
    int sensorValue = analogRead(pin);
    Serial.print("Sensor on pin ");
    Serial.print(pin);
    Serial.print(": ");
    Serial.println(sensorValue);
}
