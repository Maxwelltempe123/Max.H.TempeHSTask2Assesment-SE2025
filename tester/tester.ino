#include "ServoMotor.h"

#define LEFT_SERVO_PIN 10
#define RIGHT_SERVO_PIN 9

ServoMotor leftServo(LEFT_SERVO_PIN);
ServoMotor rightServo(RIGHT_SERVO_PIN);

void setup() {
  Serial.begin(115200);
  leftServo.attach();
  rightServo.attach();
  Serial.println("start servo");
}

void loop() {
  Serial.println("backwards");
  leftServo.setSpeed(0);  
  rightServo.setSpeed(0); 
  delay(1000);            

  Serial.println("stop");
  leftServo.setSpeed(90);  
  rightServo.setSpeed(90); 
  delay(1000);             

  Serial.println("forwards");
  leftServo.setSpeed(180);  
  rightServo.setSpeed(180); 
  delay(1000);              

  Serial.println("stop");
  leftServo.stop();  
  rightServo.stop(); 
  delay(1000);       
}