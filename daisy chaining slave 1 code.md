#include<SPI.h>
int ledPin = 8; 
int switchPin = 7;
int x;
boolean received;
byte Slavereceived;
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode (switchPin, INPUT);
  pinMode(SS, INPUT);
  pinMode(MISO, OUTPUT);
  Serial.begin (9600);
  SPCR |= _BV(SPE); 
  SPI.attachInterrupt();
}

ISR (SPI_STC_vect)                        //Inerrrput routine function 
{
  Slavereceived = SPDR;         // Value received from master if store in variable slavereceived
  received = true;                        //Sets received as True 
}


void loop(){
  if(received)                            //Logic to SET LED ON OR OFF depending upon the value recerived from master
   {
      if (Slavereceived=='0') 
      {
        for (int i=0;i<3;i++)
        {
         digitalWrite(ledPin,HIGH);
         delay(200);
         digitalWrite(ledPin, LOW);
         delay(200);  
        }              
      }
      else
      {
       SPI.transfer(Slavereceived);
      }
  }
   if (digitalRead(switchPin) == 1)
   {
    SPI.transfer('2');
   }
}
