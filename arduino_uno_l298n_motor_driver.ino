//motor1
#define ENA 5 //PWM pin
#define M1 6
#define M2 7

//motor2
#define ENB 10 //PWM pin
#define M3 8
#define M4 9

void setup()
{
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void loop()
{
  forward();
  delay(5000);
  forward_pwm();
  delay(5000);
  left();
  delay(5000);
  right();
  delay(5000);
  reverse_pwm();
  delay(5000);
  reverse();
  delay(5000);
}

void forward()
{
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void reverse()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void left()
{
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void right()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void forward_pwm()
{
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}

void reverse_pwm()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}
