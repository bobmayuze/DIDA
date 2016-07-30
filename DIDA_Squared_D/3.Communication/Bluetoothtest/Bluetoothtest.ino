void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() 
{
  
  while(Serial.available())
  {
    char c=Serial.read();
     if(c=='A')
     {
      Serial.println("Hellp I am BoooobMa");
     }

    
  }

}
