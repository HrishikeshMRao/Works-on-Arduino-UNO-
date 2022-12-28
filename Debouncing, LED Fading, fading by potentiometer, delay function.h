
int led = LOW;
int buttonold = LOW;
int ledstate = 0;
int currentTime;
int previousTime = 0;
int output;
int Brightness;
int LEDstate;
void setup()
{
  pinMode(12, INPUT);
  pinMode(A5, INPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}
void loop()
{ 
  if (digitalRead(12)==HIGH)
  {
   for (Brightness = 0; Brightness <= 255; Brightness += 1)
   {
    digitalWrite(13, 1);
    delay(10*(Brightness)/255);
    digitalWrite(13, 0);
    delay(10-10*(Brightness)/255);
   }
   for (Brightness = 255; Brightness >= 0; Brightness -= 1)
   {
    digitalWrite(13, 1);
    delay(10*(Brightness)/255);
    digitalWrite(13, 0);
    delay(10-10*(Brightness)/255);
   }
  }
  LEDstate = analogRead(A5);
  output = map(LEDstate, 0, 1023, 0, 255);
  digitalWrite(8, 1);
  delay(10*(output)/255);
  digitalWrite(8, 0);
  delay(10-10*(output)/255);
  currentTime = millis();
  if (currentTime - previousTime >= 500)
  {
    previousTime = currentTime;
     if (ledstate == LOW)
     {
       ledstate = HIGH;
     }
     else 
     ledstate = LOW;
  }
  digitalWrite(7, ledstate);
  if (digitalRead(5)==1)
  {
    int buttonnew = digitalRead(5);
    delay(150);//debouncing
    Serial.println(buttonnew);
    if ((buttonnew == HIGH) && (buttonold == LOW))
     {
      led = !led;
     }
    digitalWrite(6,led);
    buttonnew = LOW;
    buttonold = buttonnew;
  }
}
