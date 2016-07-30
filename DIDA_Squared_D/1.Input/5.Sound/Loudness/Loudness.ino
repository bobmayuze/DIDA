int val;
void setup()
{
  Serial.begin(9600);//SIG connected to A0
}

void loop()
{
  analogRead(0);
  delay(10);
  val = analogRead(0);
  Serial.println(val);
  delay(200);
}
