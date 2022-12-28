int led, x, i=0, out, sum = 0, nump = 0, numn = 1, f, total = 0, in, a[50];

void setup()
{
 pinMode(13, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(12, OUTPUT);
 pinMode(11, OUTPUT); 
 pinMode(4, INPUT);
 pinMode(5, INPUT);
 Serial.begin(9600);
 Serial.print("Total number of button push");
 Serial.print("           ");
 Serial.println("Fibonacci series"); 
}

void loop()
{ 
 out = digitalRead(5);
 delay(500);
 sum = sum + out;
 if (sum == 0)
 {
  digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(11,0);
 } 
 else 
 { 
  x = sum;
  while(x!=0)
  {
   led = x%2;
   a[i] = led;
   x = x/2;
   i++; 
  }
  i=0; 
  digitalWrite(11 , a[0]);
  digitalWrite(12 , a[1]);
  digitalWrite(13 , a[2]);    
 }  
 if (digitalRead(4)==1)
 { 
  in = digitalRead(4);
  total=total+in;
  if (total == 1)
  { 
   Serial.print(total);
   Serial.print("                                       ");
   Serial.println(numn); 
   digitalWrite(7,1);
   delay(500);
   digitalWrite(7,0);
   delay(500);
  }
  else
  {  
   f = numn;
   numn = numn + nump;
   nump = f;
   Serial.print(total);
   Serial.print("                                       ");
   Serial.println(numn);  
   for (i=0; i<numn;i++) 
   {
    digitalWrite(7,1);
    delay(500);
    digitalWrite(7,0);
    delay(500);
   }
  }  
 }
}
 

