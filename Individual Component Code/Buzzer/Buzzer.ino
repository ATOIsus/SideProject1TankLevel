const int buzzerOut = 8; // const not necessary.

void setup() {
  pinMode(buzzerOut, OUTPUT);

}

void loop() {

  tone(buzzerOut, 100);
  delay(1000);

  noTone(buzzerOut);
  delay(1000);
}
