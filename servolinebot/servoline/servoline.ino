//main .ino file that runs the methods from parent class linesystem

#include "LineSystem.h"

LineSystem lineSystem(9, 10, A2, A3);//servo motor and line sensor pins

void setup() {
    lineSystem.setup();
}

void loop() {
    lineSystem.followLine();
}
