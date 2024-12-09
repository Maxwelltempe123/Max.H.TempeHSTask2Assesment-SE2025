#include "LineSensor.h"

LineSensor::LineSensor(int sensorPin) {
    pin = sensorPin;
    thresholdLow = 0;  // initialize with default values
    thresholdHigh = 1023;
}

void LineSensor::calibrate() {
    int whiteValue = analogRead(pin);
    delay(2000);  // time to manually place sensor on black surface
    int blackValue = analogRead(pin);
    
    thresholdLow = whiteValue + (blackValue - whiteValue) / 4;  //sensor range
    thresholdHigh = blackValue - (blackValue - whiteValue) / 4;
}

bool LineSensor::isOnLine() {
    int sensorValue = analogRead(pin);
    return sensorValue >= thresholdLow && sensorValue <= thresholdHigh;
}

int LineSensor::readValue() {
    return analogRead(pin);
}

void LineSensor::debugReadings() {//for attaining system sensor values for each sensor to deterime thresholds
    int sensorValue = analogRead(pin);
    Serial.print("Sensor on pin ");
    Serial.print(pin);
    Serial.print(": ");
    Serial.println(sensorValue);
}
