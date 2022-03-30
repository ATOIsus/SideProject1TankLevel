//const int relayOutput = 2;
const int buttonInput = 3;
const int waterInput = 4;
const int buzzerOutput = 5;

int buttonPressed = LOW;
int tankStatus = LOW;

void setup() {
  Serial.begin(9600);
  //pinMode(relayOutput, OUTPUT);
  pinMode(buttonInput, INPUT);
  pinMode(waterInput, INPUT);
}

void loop() {

  if (debounceWater(tankStatus) == HIGH && tankStatus == LOW) {
    noTone(buzzerOutput);
    //digitalWrite(relayOutput, HIGH);
    //delay(1000);

    tankStatus = HIGH;
    Serial.println("Tank is not Full");

    if (debounceButton(buttonPressed) == HIGH && buttonPressed == LOW) {
      buttonPressed = HIGH;
      //digitalWrite(relayOutput, LOW);
      //delay(1000);

      Serial.println("Button Pressed, Silence the Buzzer!");
      Serial.println("Stopping buzzer.");
      noTone(buzzerOutput);
    }
    else if (debounceButton(buttonPressed) == LOW && buttonPressed == HIGH) {
      buttonPressed = LOW;
      Serial.println("Button has been reset.");
    }

  }
  else if (debounceWater(tankStatus) == LOW && tankStatus == HIGH) {
    tankStatus = LOW;
    Serial.println("Tank is Full");


    Serial.println("Playing buzzer.");
    tone(buzzerOutput, 100);
    delay(500);

  }

  //Serial.println("Stopping buzzer.");
  //noTone(buzzerOutput);
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
    delay(100);
    stateNow = digitalRead(waterInput);
  }

  Serial.println("Stopping Buzzer.");
  return stateNow;
}
