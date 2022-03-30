unsigned long time;    // Variable (time) must be an unsigned long.

void setup(){
  Serial.begin(9600);
}

void loop(){
    
  // Prints time since program started.
  
  Serial.print("Time: ");
  time = millis();
  Serial.println(time);
  
  // Wait a second so as not to send massive amounts of data
  delay(1000);
}
