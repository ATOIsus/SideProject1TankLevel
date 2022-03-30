
const int buttonInput = 2;
unsigned long firstTime = 0;
unsigned long secondTime = 0;
int buttonState = LOW;


void setup()
{
  Serial.begin(9600);
  pinMode(buttonInput, INPUT);
}

void loop()
{
  buttonState = digitalRead(buttonInput);



  if (debounceButton(buttonState) == HIGH) {
    Serial.println("Switch is On.");
    firstTime = millis();  // Record the time when switch is turned on or button is pressed.
  }


  if (firstTime > 10) {
    secondTime = millis(); // Record the secondTime after firstTime is initialized i.e. switch on.
  }

  if (secondTime - firstTime > 60000UL) {
    Serial.println("A minute has passed.");
    firstTime = 0;       // Reset the first time.
  }

  secondTime = 0;       // Reset the second time.
}



int debounceButton(int state) {
  int stateNow = digitalRead(buttonInput);
  if (state != stateNow) {
    delay(10);
    stateNow = digitalRead(buttonInput);
  }
  return stateNow;
}
