unsigned long firstTime = 0;
unsigned long secondTime = 0;
unsigned long lastFillTime = 0;
int waterState = LOW;
int prevWaterState = LOW;
int stopState = LOW;
int prevStopState = LOW;

const int waterButton = 2;
const int stopButton = 3;
const int buzzer = 8;
const int relayOut = 7;

void setup()
{
  pinMode(waterButton, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(stopButton, INPUT);
  pinMode(relayOut, OUTPUT);
  Serial.begin(9600);
}



void loop()
{

  if (firstTime > 100UL) {
    secondTime = millis(); // Record the secondTime after firstTime is initialized i.e. switch on.
  }

  bool conditionOne = millis() - lastFillTime > 1200000UL && lastFillTime != 0UL;

  if (conditionOne || lastFillTime == 0UL) { // For other time.

    if (firstTime + secondTime == 0UL) {
      waterState = digitalRead(waterButton);

      if (debounceWater(waterState) == HIGH && prevWaterState == LOW) {
        Serial.println("Switch is On for First Time.");
        prevWaterState == HIGH;
        firstTime = millis();  // Record the time when switch is turned on or button is pressed.
      } else if (debounceWater(waterState) == LOW && prevWaterState == HIGH) {
        prevWaterState == LOW;
      }
    }

    if (conditionOne) {
      // 20 minutes has passed.
      lastFillTime = 1UL; // Reset the lastFillTime.
    }
  }

  bool conditionTwo = firstTime != 0UL && secondTime != 0UL;
  if (secondTime - firstTime > 20000UL && conditionTwo) {

    Serial.println("20 seconds has passed.");

    waterState = digitalRead(waterButton);

    if (debounceWater(waterState) == HIGH) {
      Serial.println("Switch is On for Second Time.");

      lastFillTime = millis();

      tone(buzzer, 100);
      delay(500);
      tone(buzzer, 400);
      delay(500);
      tone(buzzer, 700);
      delay(500);
    }

    firstTime = 0UL;       // Reset the first time.
  }

  stopState = digitalRead(stopButton);

  if (debounceButton(stopState) == HIGH && prevStopState == LOW) {
    Serial.println("Stopping Buzzer");
    noTone(buzzer);
    // digitalWrite(7, LOW);// Turn relay OFF
    // delay(5000);// Keep it OFF for 5 seconds

    prevStopState = HIGH;
  }

  else if (debounceButton(stopState) == LOW && prevStopState == HIGH) {
    prevStopState = LOW;
  }

  secondTime = 0UL;
}



int debounceWater(int state) {
  int stateNow = digitalRead(waterButton);
  if (state != stateNow) {
    delay(100);
    stateNow = digitalRead(waterButton);
  }
  return stateNow;
}



int debounceButton(int state) {
  int stateNow = digitalRead(stopButton);
  if (state != stateNow) {
    delay(100);
    stateNow = digitalRead(stopButton);
  }
  return stateNow;
}
