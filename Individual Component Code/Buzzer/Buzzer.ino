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




/*

// Something like a melody. Better than continous sound.

void loop() {
 tone(buzzer, 100);
 delay(1000);
 tone(buzzer, 300);
 delay(1000);
}

*/
