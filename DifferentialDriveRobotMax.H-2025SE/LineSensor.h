#ifndef LINE_SENSOR_H
#define LINE_SENSOR_H

class LineSensor {
public:
    LineSensor(int pin, int threshold);
    void init();
    bool isLineDetected();

private:
    int pin;
    int threshold;
};

#endif