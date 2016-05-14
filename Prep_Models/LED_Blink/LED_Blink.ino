void setup() {

  pinMode(13, OUTPUT);   // initialize digital pin 13 as an output. 

}



void loop() {

  digitalWrite(13, 1);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second

}
