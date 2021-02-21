void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(6, INPUT);
}

void loop()
{
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
  
  delay(8000);
  
  digitalWrite(8, HIGH);
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(8, LOW);
  digitalWrite(12, LOW);

  delay(2000);

  digitalWrite(9, HIGH);
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(9, LOW);
  digitalWrite(12, LOW);

  delay(2000);

  digitalWrite(8, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);

  delay(6000);

  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(12, LOW);

  delay(6000);

  digitalWrite(8, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);

  delay(2000);

  digitalWrite(9, HIGH);
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(9, LOW);
  digitalWrite(12, LOW);

  delay(2000);
  
  digitalWrite(8, HIGH);
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(8, LOW);
  digitalWrite(12, LOW);

  delay(6000);

  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
}



