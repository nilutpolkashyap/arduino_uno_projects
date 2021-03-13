
void setup()
{
  for(int i=4;i<8;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);

  delay(5000);

  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);

  delay(5000);
}
