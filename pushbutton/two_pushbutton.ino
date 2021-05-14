int pin1state = 0;
int pin2state = 0;

void setup() {
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
}

void loop() {
  pin1state = digitalRead(3);
  pin2state = digitalRead(4);

  Serial.println("Pin 1 state : ");
  Serial.println(pin1state);
  Serial.print("\n");
  Serial.println("Pin 2 state : ");
  Serial.println(pin2state);
  Serial.print("\n");
}
