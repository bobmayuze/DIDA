// This is the project created by Yuze Bob Ma, Phantomlei, and Gavi @RPI on Aug, 24th, 2016. Just for fun!
#include <Servo.h>
Servo myservo;


const int buttonPin_A = 9;     // the number of the pushbutton pin
const int buttonPin_B = 10;     // the number of the pushbutton pin

int buttonState_A = 0;         // variable for reading the pushbutton A status
int buttonState_B = 0;         // variable for reading the pushbutton B status
int pos = 0; // set the status for the servo
bool gameIsNotStarted = true;


void setup() {
	randomSeed(analogRead(0));
  // put your setup code here, to run once:
  Serial.begin(9600); //set pote rate
  myservo.attach(12); //claim the pin the servo attached to
  myservo.write(90); //initialize the position of servo
  pinMode(buttonPin_A, INPUT_PULLUP);
  pinMode(buttonPin_B, INPUT_PULLUP);
  Serial.println("Ready!");
  delay(random(7001)+1000);
  Serial.println("GO!");

}

void loop() {
	// put your main code here, to run repeatedly:
	
  	buttonState_A = digitalRead(buttonPin_A);	// read the state of the pushbutton A value:
  	buttonState_B = digitalRead(buttonPin_B);	// read the state of the pushbutton B value:

//  	Serial.println(buttonState_A);
//  	Serial.println(buttonState_B);
       
	if (buttonState_A == 0) //Check out the button state for button A 
	{
		      Serial.println("Winner is Player A");
		myservo.write(0); //slap player B
		delay(1000);
		myservo.write(90);
		delay(1000);
		exit(0);
	}

	if (buttonState_B == 0) //Check out the button state for button B
	{
		myservo.write(180); //slap player A
		Serial.println("Winner is Player B");
		delay(1000);
		myservo.write(90);
		delay(1000);
		exit(0);
	}
}
