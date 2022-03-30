boolean buttonState = LOW;
const int buttonInput = 2;   // const is not necessary.

void setup()
{
  pinMode(buttonInput, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(2);
  if (debounceButton(buttonState) == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(10);
}


// Debounce funtion.

boolean debounceButton(boolean state) {
  boolean stateNow = digitalRead(buttonInput);
  if (state != stateNow) {
    delay(10);
    stateNow = digitalRead(buttonInput);
  }
  return stateNow;
}
