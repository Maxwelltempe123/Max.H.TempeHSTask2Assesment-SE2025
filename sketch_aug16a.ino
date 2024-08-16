void setup() {
  Serial.begin(9600);

}

void loop() {
  int LEFT_SENSOR = analogRead(A2);
  int RIGHT_SENSOR = analogRead(A3);
  return LEFT_SENSOR();
  return RIGHT_SENSOR();

  Serial.write(LEFT_SENSOR, RIGHT_SENSOR);
  delay(500);
}
