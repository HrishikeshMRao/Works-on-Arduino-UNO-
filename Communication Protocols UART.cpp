# Tinkercad-arduino
# SLAVE MCU CODE
char data_rcvd;
void setup()
{
 pinMode(4, OUTPUT);
 Serial.begin(9600); 
}  
void loop()
{
  if(Serial.available())
  {
    data_rcvd = Serial.read();   // read one byte from serial buffer and save to data_rcvd
    if (data_rcvd == '1') 
    {
     digitalWrite(4,1);
     delay(10); 
    }
    else
    {
     digitalWrite(4, 0);
     delay(500);
    }  
  }
}
# MASTER MCU CODE
void setup()
{
 pinMode(6, INPUT);
 Serial.begin(9600);  
}
void loop()
{
  if (digitalRead(6) == 1)
  {  
   Serial.write('1');
   delay(10); 
  }
  else
  {
   Serial.write('0');
   delay(500); 
  }  
}
  
