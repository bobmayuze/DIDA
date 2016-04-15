#include <Servo.h> 

Servo hand;  // create servo object to control a servo 
Servo rotation; 
Servo right;                 
Servo left;


int handpos = 0;
int rotationpos = 0;
int rightpos = 0;
int leftpos = 0;    // variable to store the servo position 

void setup() 
{ 
  Serial.begin(9600);
  hand.attach(9);  
  rotation.attach(11);
  right.attach(12);
  left.attach(13);   //Connet the servos to the proper Pin

  hand.write(0);
  rotation.write(90);
  right.write(90);
  left.write(0);   //Set up the Uarm



} 

void hand_open()
{
  handpos = handpos+1;
  hand.write(handpos);
}

void hand_close()
{
  handpos = handpos-1;
  hand.write(handpos);
}

void rotation_right()
{
  rotationpos = rotationpos + 1;
  rotation.write(rotationpos);
}

void rotation_left()
{
  rotationpos = rotationpos - 1;
  rotation.write(rotationpos);
}


void right_up()
{
  rightpos = rightpos - 1;
  right.write(rightpos);
}

void right_down()
{
  rightpos = rightpos + 1;
  right.write(rightpos);

}

void left_frot()
{
  leftpos = leftpos + 1;
  left.write(leftpos); 
}

void left_back()
{
  leftpos = leftpos - 1;
  left.write(leftpos);
}

void loop() 
{ 
    char c=Serial.read();
    if (c == 'W' )//Input W
      hand_open();//Rooooooll!!
    if (c == 'S' )
      hand_close();
    if (c == 'A' )//Input W
      rotation_left();//Rooooooll!!
    if (c == 'D' )
      rotation_right();
    if (c == 'Q' )//Input W
      right_up();//Rooooooll!!
    if (c == 'E' )
      right_down();
    if (c == 'X' )//Input W
      left_back();//Rooooooll!!
    if (c == 'K' )
      left_frot();



}