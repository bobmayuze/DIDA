//initializes/defines the output pin of the LM35 temperature sensor
int outputpin= A0;
int led = 9;
//this sets the ground pin to LOW and the input voltage pin to high
void setup()
{
Serial.begin(9600);
pinMode(led,OUTPUT);
}

//main loop
void loop()
{
int rawvoltage= analogRead(outputpin);
float millivolts= (rawvoltage/1024.0) * 5000;
float celsius= millivolts/10;
Serial.print(celsius);
analogWrite(led,rawvoltage);
Serial.print(" degrees Celsius, ");

Serial.print((celsius * 9)/5 + 32);
Serial.println(" degrees Fahrenheit");
delay(1000);

}
