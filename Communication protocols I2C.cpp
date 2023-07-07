# Tinkercad-arduino
# MASTER MCU CODE
#include<Wire.h>
void setup()
{
  pinMode(7, INPUT);
  Wire.begin();
}
void loop() 
{
  if (digitalRead(7)== 1)
  { 
   Wire.beginTransmission(8); 
   Wire.write('1');
   Wire.endTransmission();
   delay(10); 
  }
  else
  {
   Wire.beginTransmission(8); 
   Wire.write('0');
   Wire.endTransmission(); 
   delay(500);
  }
}  
# SLAVE MCU CODE
#include<Wire.h>
char I2c;
void setup()
{
 pinMode(4, OUTPUT);
 Wire.begin(8);
 Wire.onReceive(receiveEvent);
}  
void loop()
{
 delay(10); 
}
void receiveEvent(int I2c) 
{   
 if (Wire.available())
  {
    I2c = Wire.read();
    if (I2c =='1')
    {
     digitalWrite(4,1);  
    }  
    else 
    {  
     digitalWrite(4,0);
     delay(500); 
    }
  }  
}
