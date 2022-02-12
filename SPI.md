# Tinkercad-arduino
# MASTER CODE
#include<SPI.h>
int value, x;
void setup()
{
  pinMode(7, INPUT);
  SPI.begin();
  digitalWrite(SS, HIGH);
  SPCR=(1<<SPE)|(1<<MSTR);
  SPI.setClockDivider(SPI_CLOCK_DIV8); 
  Serial.begin(9600);
}
void loop() 
{
 value = digitalRead(7);
 Serial.write('1');
 if(value == HIGH)                
 {
  x = 1; 
 }
 else
 {
  x = 0;
 }
 Serial.write('1');
 digitalWrite(SS,LOW);
 SPI.transfer(x);
 digitalWrite(SS,HIGH);
 delay(2000); 
}  
# SLAVE CODE
#include<SPI.h>
volatile boolean received;
volatile byte Slavereceived;
void on()                        
{        
  received = true;
}
void setup()
{
 pinMode(4, OUTPUT);
 pinMode(10, INPUT);
 pinMode(12, INPUT);
 pinMode(MISO, OUTPUT);
 SPCR = (1<<SPE);
 received = false; 
 Serial.begin(9600); 
 attachInterrupt(digitalPinToInterrupt (12), on, HIGH); 
}
void loop()
{ 
  if(received)
  {
   Slavereceived = SPDR; 
   if (Slavereceived==1) 
   {  
    digitalWrite(4,HIGH); 
   }
  }  
  else
  {
   digitalWrite(4,LOW);          
  }
  received = false;   
}

