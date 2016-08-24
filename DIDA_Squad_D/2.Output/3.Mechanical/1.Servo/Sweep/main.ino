#include <Servo.h>
Servo myservo;


const int buttonPin = 2;     // the number of the pushbutton pin
const int buttonPin = 3;     // the number of the pushbutton pin

int buttonState_A = 0;         // variable for reading the pushbutton A status
int buttonState_B = 0;         // variable for reading the pushbutton B status
int pos = 0 // set the status for the servo


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
	if (/* condition */)
	{
		/* code */
	}

}
