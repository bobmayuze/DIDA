void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
}


void loop(){
  int pr = analogRead(A0);

  Serial.println(pr);

  delay(1000);
}

