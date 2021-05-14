const int ledpin1 = 3;
const int ledpin2 = 4;

void setup()
{
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
}

void loop()
{
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);

  delay(2000);

  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);

  delay(1000);
}
