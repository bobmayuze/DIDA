int ledcolor = 0;
int a = 1000; //this sets how long the stays one color for
int red = 11; //this sets the red led pin
int green = 12; //this sets the green led pin
int blue = 13; //this sets the blue led pin

void setup() { //this sets the output pins

	pinMode(red, OUTPUT);
	pinMode(green, OUTPUT);
	pinMode(blue, OUTPUT);
}


void loop() {
	int ledcolor = random(7); //this randomly selects a number between 0 and 6

	switch (ledcolor) {
	case 0: //if ledcolor equals 0 then the led will turn red
	analogWrite(red, 204);
	delay(a);
	analogWrite(red, 0);
	break;
	case 1: //if ledcolor equals 1 then the led will turn green
	digitalWrite(green, HIGH);
	delay(a);
	digitalWrite(green, LOW);
	break;
	case 2: //if ledcolor equals 2 then the led will turn blue
	digitalWrite(blue, HIGH);
	delay(a);
	digitalWrite(blue, LOW);
	break;
	case 3: //if ledcolor equals 3 then the led will turn yellow
	analogWrite(red, 160);
	digitalWrite(green, HIGH);
	delay(a);
	analogWrite(red, 0);
	digitalWrite(green, LOW);
	break;
	case 4: //if ledcolor equals 4 then the led will turn cyan
	analogWrite(red, 168);
	digitalWrite(blue, HIGH);
	delay(a);
	analogWrite(red, 0);
	digitalWrite(blue, LOW);
	break;
	case 5: //if ledcolor equals 5 then the led will turn magenta
	digitalWrite(green, HIGH);
	digitalWrite(blue, HIGH);
	delay(a);
	digitalWrite(green, LOW);
	digitalWrite(blue, LOW);
	break;
	case 6: //if ledcolor equals 6 then the led will turn white
	analogWrite(red, 100);
	digitalWrite(green, HIGH);
	digitalWrite(blue, HIGH);
	delay(a);
	analogWrite(red, 0);
	digitalWrite(green, LOW);
	digitalWrite(blue, LOW);
	break;
	}
}
