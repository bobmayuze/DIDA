#define trigpin 5//set trigpin
#define echopin 6//set echopin
#include <Servo.h>

Servo myservo;// declare servo name type servo
  int duration, distance;//declare variable for unltrasonic sensor
  
void setup() {
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
 
  pinMode(echopin, INPUT);
  myservo.attach(2);// attach your servo
  myservo.writeMicroseconds(1500);
  // put your setup code here, to run once:
}
void loop() {
 myservo.write(90);// always set servo to 90 to position it to the middle
//ultrasonic code 
 digitalWrite(trigpin,HIGH);
  _delay_ms(500);
  digitalWrite(trigpin, LOW);
  
  duration=pulseIn(echopin,HIGH); 
  distance=(duration/2)/29.1; 
 if(distance <=20)// if ultrasonic sensor detects an obstacle less than 20cm in 90 degree angle.
 {
 myservo.write(0); //servo rotates at full speed to the right
 delay(600);
}
else
{
  myservo.write(90);// else servo stays at 90 degree angle.
  delay(600);
}
  Serial.print("cm"); //print distance unit cm
Serial.println(distance);//distance
 
  // put your main code here, to run repeatedly:
}
