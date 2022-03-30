#define buzzer 4
#define buttonInput 5

void setup()
{
  Serial.begin(9600);
  pinMode(buttonInput, INPUT);
}

void loop()
{
  if (debounceButton(digitalRead(buttonInput)) == HIGH) {
    tone(buzzer, 2000);
  } else {
    noTone(buzzer);
  }

}



int debounceButton(int state) {
  int stateNow = digitalRead(buttonInput);
  if (state != stateNow) {
    delay(10);
    stateNow = digitalRead(buttonInput);
  }
  return stateNow;
}
