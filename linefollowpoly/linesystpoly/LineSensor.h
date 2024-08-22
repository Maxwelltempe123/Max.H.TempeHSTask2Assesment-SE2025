#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <Arduino.h>

class LineSensor {
private:
    int pin;

public:
    LineSensor(int sensorPin);
    int readValue();
    bool isOnLine(int threshold);  
};

#endif