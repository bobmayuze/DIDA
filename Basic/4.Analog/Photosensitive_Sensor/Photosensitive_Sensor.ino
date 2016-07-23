void setup(){
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

int pr_min = 400;

void loop(){
  int pr = analogRead(A0);

  Serial.println(pr);

  delay(1000);
}

