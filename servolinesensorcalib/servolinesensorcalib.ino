#include "LineSystem.h"

LineSystem robotSystem(9, 10, A2, A3);//pins for servo and sensors

void setup() {
    Serial.begin(9600);

    // Calibrate sensors at the start
    robotSystem.calibrateSensors();

    // Check sensor readings
    robotSystem.debugSensors();
}

void loop() {
    //main system logic
    robotSystem.adjustMotors();

    // Continuously debug sensors if needed
    robotSystem.debugSensors();
}
