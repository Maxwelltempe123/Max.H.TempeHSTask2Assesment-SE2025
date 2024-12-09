#ifndef LINESENSOR_H
#define LINESENSOR_H

class LineSensor {
public:
    LineSensor(int pin, int thresholdWhite, int thresholdBlack);
    int readValue();
    bool isOnLine();
    bool isOnWhite();

private:
    int sensorPin;
    int thresholdWhite;
    int thresholdBlack;
};

#endif
