unsigned long firstTime = 0;
unsigned long secondTime = 0;
int waterState = LOW;
int stopState = LOW;

const int waterButton = 2;
const int stopButton = 3;
const int buzzer = 8;

void setup()
{
  pinMode(waterButton, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(stopButton, INPUT);
  Serial.begin(9600);
}



void loop()
{
  waterState = digitalRead(waterButton);

  if (firstTime + secondTime == 0UL) {
    if (debounceWater(waterButton) == LOW) {
      Serial.println("Switch is On for First Time.");
      firstTime = millis();  // Record the time when switch is turned on or button is pressed.
    } 
  }

  if (firstTime > 10) {
    secondTime = millis(); // Record the secondTime after firstTime is initialized i.e. switch on.
  }

  if (secondTime - firstTime > 60000UL) {
    Serial.println("A minute has passed.");

    if (debounceWater(waterState) == LOW) {
      Serial.println("Switch is On for Second Time.");

      tone(buzzer, 100);
      delay(1000);
      tone(buzzer, 400);
      delay(1000);
      tone(buzzer, 700);
      delay(1000);
    }

    firstTime = 0;       // Reset the first time.
  }

  stopState = digitalRead(stopButton);

  if (debounceButton(stopState) == LOW) {
    Serial.println("Stopping Buzzer");
    noTone(buzzer);
  }


  secondTime = 0;       // Reset the second time.
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
