#include <LiquidCrystal.h> //申明1602液晶的函数库
//申明1602液晶的引脚所连接的Arduino数字端口，8线或4线数据模式，任选其一
LiquidCrystal lcd(12,11,10,9,8,7,6,5,4,3,2);   //8数据口模式连线声明
//LiquidCrystal lcd(12,11,10,5,4,3,2); //4数据口模式连线声明
int i;
int outputpin= A0;


void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);      //初始化1602液晶工作                       模式
                       //定义1602液晶显示范围为2行16列字符

}
void loop()
{
  int rawvoltage= analogRead(outputpin);
  float millivolts= (rawvoltage/1024.0) * 5000;
  float celsius= millivolts/10;
  Serial.print(celsius);
  Serial.print(" degrees Celsius");
  delay(1000);
  
  lcd.home();        //把光标移回左上角，即从头开始输出   
  lcd.print("Room Temp Is"); //显示
  lcd.setCursor(0,1);   //把光标定位在第1行，第0列
  lcd.print(celsius);       //显示
  delay(1000);
  lcd.clear();
}//初始化已完成显示，主循环无动作
