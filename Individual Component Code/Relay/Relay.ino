const int relayOut = 7;  // const not necessary.

void setup() {
  pinMode(7, OUTPUT);   // Connected to S terminal of Relay & Digital Pin 7 of Arduino.
}

void loop() {

  digitalWrite(7, HIGH); // Turn relay ON
  delay(3000);// Keep it ON for 3 seconds

  digitalWrite(7, LOW);// Turn relay OFF
  delay(5000);// Keep it OFF for 5 seconds

}
