int buttonState = LOW;
int buttonInput = 2;
int b1 = LOW;
void setup()
{
  Serial.begin(9600);
  pinMode(buttonInput, INPUT);
  for (int i = 2; i <= 12; i++) {
    pinMode(i, INPUT);
  }
}

void loop()
{
  for (int i = 2; i <= 12; i ++) {
    buttonInput = i;

    
    buttonState = digitalRead(buttonInput);
    
    
    if (b1 == LOW && debounceButton(buttonState) == HIGH) {
      b1 = HIGH;
      Serial.print("  Digital Pin: ");
      Serial.println(i);
      Serial.print("\tState: ");
      Serial.print(b1 = HIGH);
    } else if (b1 == HIGH && debounceButton(buttonState) == LOW)  {
      b1 = LOW;
    }

  }

  delay(200);
}



// Debounce funtion.

int debounceButton(int state) {
  int stateNow = digitalRead(buttonInput);
  if (state != stateNow) {
    delay(50);
    stateNow = digitalRead(buttonInput);
  }
  return stateNow;
}
