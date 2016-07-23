// Pins
// Fill in the pins you used on your own setup.
// WARNING: Make sure you have resistors connected between the rows and the arduino.

#define ROW_1 2
#define ROW_2 3
#define ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7 8
#define ROW_8 9

#define COL_1 10
#define COL_2 11
#define COL_3 12
#define COL_4 13
#define COL_5 A0
#define COL_6 A1
#define COL_7 A2
#define COL_8 A3

const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};

// The display buffer
// It's prefilled with a smiling face (1 = ON, 0 = OFF)
byte smile[] = {B01111110,B10000001,B10100101,B00000000,B00011000,B01000010,B00111100,B00000000};
byte nutral[] = {B11111111,B10000001,B10100101,B10000001,B10000001,B10111101,B10000001,B11111111};
byte angry[] = {B11111111,B10000001,B10100101,B10000001,B00000000,B00111100,B01000010,B00000000};

float timeCount = 0;

void setup() {
    // Open serial port
    Serial.begin(9600);
    
    // Set all used pins to OUTPUT
    // This is very important! If the pins are set to input
    // the display will be very dim.
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
}

void loop() {
  // This could be rewritten to not use a delay, which would make it appear brighter
delay(5);
timeCount += 1;
if(timeCount <  200) {
drawScreen(nutral);
} else if (timeCount <  230) {
// do nothing
} else if (timeCount <  400) {
drawScreen(smile);
} else if (timeCount <  430) {
// nothing
} else if (timeCount <  600) {
drawScreen(nutral);
} else if (timeCount <  630) {
// nothing
} else if (timeCount <  800) {
drawScreen(angry);
} else if (timeCount <  830) {
// nothing
} else if (timeCount <  1000) {
drawScreen(smile);
} else if (timeCount <  1030) {
// nothing
} else if (timeCount <  1200) {
drawScreen(angry);
} else if (timeCount <  1230) {
// nothing
} else {
// back to the start
timeCount = 0;
}
}
 void  drawScreen(byte buffer2[]){
     
    
   // Turn on each row in series
    for (byte i = 0; i < 8; i++) {
        setColumns(buffer2[i]); // Set columns for this specific row
        
        digitalWrite(rows[i], HIGH);
        delay(2); // Set this to 50 or 100 if you want to see the multiplexing effect!
        digitalWrite(rows[i], LOW);
        
    }
}


void setColumns(byte b) {
    digitalWrite(COL_1, (~b >> 0) & 0x01); // Get the 1st bit: 10000000
    digitalWrite(COL_2, (~b >> 1) & 0x01); // Get the 2nd bit: 01000000
    digitalWrite(COL_3, (~b >> 2) & 0x01); // Get the 3rd bit: 00100000
    digitalWrite(COL_4, (~b >> 3) & 0x01); // Get the 4th bit: 00010000
    digitalWrite(COL_5, (~b >> 4) & 0x01); // Get the 5th bit: 00001000
    digitalWrite(COL_6, (~b >> 5) & 0x01); // Get the 6th bit: 00000100
    digitalWrite(COL_7, (~b >> 6) & 0x01); // Get the 7th bit: 00000010
    digitalWrite(COL_8, (~b >> 7) & 0x01); // Get the 8th bit: 00000001
    
    // If the polarity of your matrix is the opposite of mine
    // remove all the '~' above.
}
