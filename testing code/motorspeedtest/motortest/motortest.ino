#include <Servo.h>

Servo leftMotor;
Servo rightMotor;

void setup() {
    leftMotor.attach(9);
    rightMotor.attach(10);
    leftMotor.writeMicroseconds(1520);  // Set to forward speed
    rightMotor.writeMicroseconds(1480); // Set to forward speed
}

void loop() {
    // Keep the motors running at the set speed
}