int led = 9;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
}


void loop(){
  int sensorValue = analogRead(A0);

  Serial.println(sensorValue);
  analogWrite(led,sensorValue);

  delay(1000);
}
