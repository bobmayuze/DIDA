int ledPin = 9;
void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(A0, INPUT);
}


void loop(){
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  analogWrite(ledPin,sensorValue);
  delay(1000);
}

