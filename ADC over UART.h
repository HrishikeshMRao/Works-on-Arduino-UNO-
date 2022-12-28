# Tinkercad-arduino
# MASTER CODE
int LEDstate;
int output;
void setup()
{
 pinMode(A5, INPUT);
 Serial.begin(11500); 
}
void loop()
{
  LEDstate = analogRead(A5);
  output = map(LEDstate, 0, 1023, 0, 255);
  Serial.write(output);
  delay(10);
}
# SLAVE CODE
int output;
void setup()
{
  pinMode(5, OUTPUT);
  Serial.begin(11500);
}
void loop()
{
  if(Serial.available())
  {
   output = Serial.read(); 
   analogWrite(5, output);
  }
}  
