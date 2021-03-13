
void setup()
{
  for(int i=4;i<6;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);

  delay(5000);

  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);

  delay(5000);
}
