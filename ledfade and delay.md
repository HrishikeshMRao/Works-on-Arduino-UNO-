int i=0,n=0,k;
void setup()
{
 pinMode(12,INPUT);
 pinMode(6,OUTPUT); 
}
void delay_ms(int m)
{
  for(int j=0;j<m;j++)
  {
   delay(0.1); 
   if (digitalRead(12))
   {
    delay(500); 
    n++;    		
    break;
   }
  }  
} 
void loop()
{ 
  if(n>=10)
  n%=10;  
  k=n%2;
  switch(k)
  {
   case 0: 
   {
    for(i=0;i<=255;i++)
    {
     if (digitalRead(12))
     {
      n++;
	  break;
     }
     analogWrite(6,i);//create pwm
     delay(5); 
    }
    if (digitalRead(12))
    {
     delay(500);
     break;
    }
    for(i=255;i>=0;i--)
    {
     if (digitalRead(12))
     {
      delay(500);
      n++;
      break;
     }
     analogWrite(6,i);
     delay(5); 
    }
    break; 
   }
   case 1:
   {
    analogWrite(6,i);//keep the i value and blink
    delay_ms(10000);
    analogWrite(6,0);
    delay_ms(10000);
    break; 
   }
  }  
}
