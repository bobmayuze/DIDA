#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos =0;    // variable to store the servo position 
 
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(4);  // attaches the servo on pin 9 to the servo object 
} 

void rotate()
{
  Serial.println("OMG");
  pos=pos+45;
  myservo.write(pos);
  Serial.println("U did");
}

void loop() 
{ 
                             
    char c=Serial.read();
    if (c == 'W' )//Input W
      rotate();//Rooooooll!!
    
} 

