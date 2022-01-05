int ledstate = LOW;
int buttonold = LOW;
void setup()
{
  pinMode(3, INPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  int buttonnew = digitalRead(3);
  if ((buttonnew == HIGH) && (buttonold == LOW))
  {
   ledstate = !ledstate;
  }
  digitalWrite(11,ledstate);
  buttonnew = LOW;
  buttonold = buttonnew;

  digitalWrite(13, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(13, LOW);
  delay(500); // Wait for 500 millisecond(s)

  digitalWrite(2, HIGH);
}
