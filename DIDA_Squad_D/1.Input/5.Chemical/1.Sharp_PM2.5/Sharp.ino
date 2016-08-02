// ==产品概述==
// 夏普灰尘传感器GP2Y10价格比较便宜，能够检测出室内空气中的灰尘和烟尘含量，检测原理是传感器中心有个洞可以让空气自由流过，定向发射LED光，通过检测经过空气中的灰尘折射过后的光线来判断灰尘的含量。
// ==规格参数==
// *工作电压: 5 ~ 7V
// *工作温度: -10 ~ 65摄氏度
// *最大电流: 20mA
// ==接线方式==
// #Sharp pin 1 (V-LED) => 5V 串联1个150欧姆的电阻（最好在电阻一侧和GND之间再串联一个220uf的电容）
// #Sharp pin 2 (LED-GND) => GND
// #Sharp pin 3 (LED) => Arduino PIN 2 （开关LED）
// #Sharp pin 4 (S-GND) => GND
// #Sharp pin 5 (Vo) => Arduino A0 pin （空气质量数据通过电压模拟信号输出）
// #Sharp pin 6 (Vcc) => 5V
// ===例子程序===

int voutPin = 0; // 连接模拟口0
int ledPin = 2; // 连接数字口2
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
void setup(){
Serial.begin(9600);
pinMode(ledPin,OUTPUT);
}


void loop(){
digitalWrite(ledPin,LOW); // power on the LED
delayMicroseconds(samplingTime);

voMeasured = analogRead(voutPin); // read the dust value

delayMicroseconds(deltaTime);
digitalWrite(ledPin,HIGH); // turn the LED off
delayMicroseconds(sleepTime);

// 0 - 5V mapped to 0 - 1023 integer values
// recover voltage
calcVoltage = (float)voMeasured * (5.0 / 1024.0);

// linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
// Chris Nafis (c) 2012
if ( calcVoltage >= 0.6 )
{
     dustDensity = 0.17 * calcVoltage - 0.1;
}
else
{
     dustDensity = 0;
}

Serial.print("Raw Signal Value (0-1023): ");
Serial.print(voMeasured);

Serial.print(" - Voltage: ");
Serial.print(calcVoltage);
Serial.print("V");

Serial.print(" - Dust Density: ");

if( calcVoltage > 3.5 )
{
    Serial.print(">");  // unit: mg/m3
}

Serial.print(dustDensity);
Serial.println(" mg/m3");

delay(1000);

} 