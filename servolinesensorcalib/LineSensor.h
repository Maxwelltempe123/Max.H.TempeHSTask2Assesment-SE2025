#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <Arduino.h>

class LineSensor {
private:
    int pin;//analog pins
    int thresholdLow;//thresholds for determining on and off line readings
    int thresholdHigh;

public:
    LineSensor(int pin);
    void calibrate();
    bool isOnLine();
    int readValue();   // For debugging or further use
    void debugReadings();  // To monitor sensor values through Serial
};

#endif
