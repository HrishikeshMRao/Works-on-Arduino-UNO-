# MASTER code 
#include<SPI.h>
int value, x;
int led = 6;
char Slavereceived;
bool received = false;
void setup()
{
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(led, OUTPUT);
  SPI.begin();
  digitalWrite(SS, HIGH);
  SPCR=(1<<SPE)|(1<<MSTR);
  SPI.setClockDivider(SPI_CLOCK_DIV8); 
  Serial.begin(9600);
  SPI.attachInterrupt();
}
ISR (SPI_STC_vect)                        //Inerrrput routine function 
{
  Slavereceived = SPDR;         // Value received from master if store in variable slavereceived
  received = true;                        //Sets received as True 
}
void loop() 
{
 if (digitalRead(7)== 1)
 {
  x = 0; 
  Serial.write('x');
  digitalWrite(SS, LOW);
  SPI.transfer('x');
  digitalWrite(SS, HIGH);
  delay(1000); 
 }
 else if (digitalRead(8)==1)
 {
  x = 1;
  Serial.write('x');
  digitalWrite(SS, LOW);
  SPI.transfer('x');
  digitalWrite(SS, HIGH);
  delay(1000); 
 } 
 if (received)
 {
   char i = SPDR;
   if (i == '2') 
   {
     digitalWrite(led, HIGH);
     delay(200);
     digitalWrite(led, LOW);
     delay(200);
   } 
    else if (i == '3') 
   {
     digitalWrite(led, HIGH);
     delay(200);
     digitalWrite(led, LOW);
     delay(200);
   }
 }
} 
