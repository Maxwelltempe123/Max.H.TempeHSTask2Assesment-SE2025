#ifndef LINESENSOR_H
#define LINESENSOR_H

class LineSensor {
  private:
    int pin;
  public:
    LineSensor(int pin);
    void init();
    bool isLineDetected();
};

#endif