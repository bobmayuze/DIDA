
int potpin = A0;//指定模拟端口A0
int val = 0;//声明临时变量

void setup()
{
  Serial.begin(9600);//设置串口波特率为9600
}

void loop()
{
  val = analogRead(potpin); //读取A0口的电压值并赋值到val
  Serial.println(val); //串口发送val值
}

