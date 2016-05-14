
int Motor = 9;           // the pin that the Motor is attached to
int Speed = 0;    // how bright the Motor is
int fadeAmount = 5;    // how many points to fade the Motor by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(Motor, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the Speed of pin 9:
  analogWrite(Motor, Speed);

  // change the Speed for next time through the loop:
  Speed = Speed + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (Speed == 0 || Speed == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

