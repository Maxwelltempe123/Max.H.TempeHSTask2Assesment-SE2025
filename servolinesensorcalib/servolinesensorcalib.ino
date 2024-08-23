#include "LineSystem.h"

LineSystem robotSystem(9, 10, A2, A3);

void setup() {
    Serial.begin(9600);

    // Calibrate sensors at the start
    robotSystem.calibrateSensors();

    // Optional: Check sensor readings
    robotSystem.debugSensors();
}

void loop() {
    robotSystem.adjustMotors();

    // Optional: Continuously debug sensors if needed
    // robotSystem.debugSensors();
}
