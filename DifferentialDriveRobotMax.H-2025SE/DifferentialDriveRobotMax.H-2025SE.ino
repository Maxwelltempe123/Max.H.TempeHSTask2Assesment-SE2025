#include <Servo.h>

class Servo
{

}

Servo servo9;
Servo servo10;

void setup()
{
  servo9.attach(9, 700, 2300);
  servo10.attach(10, 700, 2300);
}

void loop()
{
  servo9.writeMicroseconds(1500);
  servo10.writeMicroseconds(1500);
  delay(100)
}


