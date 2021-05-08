void setup()
{
  for(int i=4;i<11;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);

  delay(3000);

  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);

  delay(3000);
}
