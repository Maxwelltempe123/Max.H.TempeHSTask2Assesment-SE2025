#include <Arduino.h>
#include <Servo.h>

Servo leftServoMotor;
Servo rightServoMotor;

int pos = 0


void setup() {
  leftServoMotor.attach(9, 90, 180);
  rightServoMotor.attach(10, 90, 180);
}

void loop() {
  leftServoMotor.write(180);
  delay(200);
  rightServoMotor.write(180);
  delay(200);
}
