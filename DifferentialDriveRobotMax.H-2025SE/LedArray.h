#include "Arduino_LED_Matrix.h"
ArduinoLedMatrix matrix;

void setup(){
  serial.begin(9600);
  matrix.begin();
}