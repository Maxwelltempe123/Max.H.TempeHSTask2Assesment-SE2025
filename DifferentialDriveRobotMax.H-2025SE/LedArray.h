#include "LEDArray.h"
#include <Arduino.h>

LEDArray::LEDArray(int dataPin, int clockPin, int latchPin)
  : dataPin(dataPin), clockPin(clockPin), latchPin(latchPin) {}

void LEDArray::init() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void LEDArray::clear() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
  shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
  digitalWrite(latchPin, HIGH);
}

void LEDArray::displayLineDetected() {
  digitalWrite(latchPin, LOW);
  // Example pattern for line detected
  shiftOut(dataPin, clockPin, LSBFIRST, 0xFF); // Modify as per your matrix setup
  shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
  digitalWrite(latchPin, HIGH);
}

void LEDArray::displayStop() {
  digitalWrite(latchPin, LOW);
  // Example pattern for stop
  shiftOut(dataPin, clockPin, LSBFIRST, 0x00); // Modify as per your matrix setup
  shiftOut(dataPin, clockPin, LSBFIRST, 0xFF);
  digitalWrite(latchPin, HIGH);
}