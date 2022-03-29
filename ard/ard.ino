const int relayOutput = 2;
const int buttonInput = 3;
const int waterInput = 4;

int buttonPressed = LOW;
int tankStatus = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(relayOutput, OUTPUT);
  pinMode(buttonInput, INPUT);
  pinMode(waterInput, INPUT);
}

void loop() {

  if (debounceWater(tankStatus) == HIGH && tankStatus == LOW) {
    digitalWrite(relayOutput, HIGH);
    delay(1000);

    tankStatus = HIGH;
    Serial.println("Tank is Full");

    if (debounceButton(buttonPressed) == HIGH && buttonPressed == LOW) {
      buttonPressed = HIGH;
      digitalWrite(relayOutput, LOW);
      delay(1000);

      Serial.println("Button Pressed, Silence the Buzzer!");
    }
    else if (debounceButton(buttonPressed) == LOW && buttonPressed == HIGH) {
      buttonPressed = LOW;
      Serial.println("Button has been reset.");
    }

  }
  else if (debounceWater(tankStatus) == LOW && tankStatus == HIGH) {
    tankStatus = LOW;
    Serial.println("Tank is not Full");
  }


}


boolean debounceButton(boolean state) {

  boolean stateNow = digitalRead(buttonInput);

  if (state != stateNow) {
    delay(10);
    stateNow = digitalRead(buttonInput);
  }

  return stateNow;
}


boolean debounceWater(boolean state) {

  boolean stateNow = digitalRead(waterInput);

  if (state != stateNow) {
    delay(10);
    stateNow = digitalRead(waterInput);
  }

  return stateNow;
}
