const int waterInput = 4;
int tankStatus = LOW;
int preTankStatus = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(waterInput, INPUT);
}

void loop() {
  if (debounceWater(tankStatus) == HIGH && preTankStatus == LOW) {
    preTankStatus = HIGH;
    Serial.println("Tank is not Full");
  }
  else if (debounceWater(tankStatus) == LOW && preTankStatus == HIGH) {
    preTankStatus = LOW;
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
