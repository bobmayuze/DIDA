#include <Wire.h>
byte Version[3];
int8_t x_data;
int8_t y_data;
int8_t z_data;
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(0x0A); // address of the accelerometer
  // low pass filter, range settings
  Wire.write(0x20);
  Wire.write(0x05);
  Wire.endTransmission();

}

void AccelerometerInit()
{
  Wire.beginTransmission(0x0A); // address of the accelerometer
  // reset the accelerometer
  Wire.write(0x04); // Y data
  Wire.endTransmission();
  Wire.requestFrom(0x0A, 1);   // request 6 bytes from slave device #2
  while (Wire.available())   // slave may send less than requested
  {
    Version[0] = Wire.read(); // receive a byte as characte
  }
  x_data = (int8_t)Version[0] >> 2;

  Wire.beginTransmission(0x0A); // address of the accelerometer
  // reset the accelerometer
  Wire.write(0x06); // Y data
  Wire.endTransmission();
  Wire.requestFrom(0x0A, 1);   // request 6 bytes from slave device #2
  while (Wire.available())   // slave may send less than requested
  {
    Version[1] = Wire.read(); // receive a byte as characte
  }
  y_data = (int8_t)Version[1] >> 2;

  Wire.beginTransmission(0x0A); // address of the accelerometer
  // reset the accelerometer
  Wire.write(0x08); // Y data
  Wire.endTransmission();
  Wire.requestFrom(0x0A, 1);   // request 6 bytes from slave device #2
  while (Wire.available())   // slave may send less than requested
  {
    Version[2] = Wire.read(); // receive a byte as characte
  }
  z_data = (int8_t)Version[2] >> 2;

  Serial.print("X=");
  Serial.print(x_data);         // print the character
  Serial.print("  ");
  Serial.print("Y=");
  Serial.print(y_data);         // print the character
  Serial.print("  ");
  Serial.print("Z=");
  Serial.println(z_data);
}

void loop()
{
  AccelerometerInit();
  delay(100);

}
