#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <Arduino.h>

class LineSensor {
private:
    int pin;
    int thresholdLow;
    int thresholdHigh;

public:
    LineSensor(int pin);
    void calibrate();
    bool isOnLine();
    int readValue();   // For debugging or further use
    void debugReadings();  // To monitor sensor values through Serial
};

#endif
