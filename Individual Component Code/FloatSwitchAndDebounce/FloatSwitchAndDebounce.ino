const int waterInput = 4;
int tankStatus = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(waterInput, INPUT);
}

void loop() {
  if (debounceWater(tankStatus) == HIGH && tankStatus == LOW) {
    tankStatus = HIGH;
    Serial.println("Tank is not Full");
  }
  else if (debounceWater(tankStatus) == LOW && tankStatus == HIGH) {
    tankStatus = LOW;
    Serial.println("Tank is Full");
  }
}



// Debounce Fucntion.

int debounceWater(int state) {
  int stateNow = digitalRead(waterInput);
  if (state != stateNow) {
    delay(100);
    stateNow = digitalRead(waterInput);
  }
  return stateNow;
}
