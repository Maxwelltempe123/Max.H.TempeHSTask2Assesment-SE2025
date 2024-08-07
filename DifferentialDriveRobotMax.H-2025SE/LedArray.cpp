#ifndef LEDARRAY_H
#define LEDARRAY_H

class LEDArray {
  private:
    int dataPin;
    int clockPin;
    int latchPin;
  
  public:
    LEDArray(int dataPin, int clockPin, int latchPin);
    void init();
    void displayLineDetected();
    void displayStop();
    void clear();
};

#endif