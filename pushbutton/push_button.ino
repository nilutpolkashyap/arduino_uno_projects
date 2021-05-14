
int pin1state = 0;

void setup() {
  pinMode(3, INPUT);
  Serial.begin(9600);
}

void loop() {
  pin1state = digitalRead(3);

  Serial.println("Pin 1 state : ");
  Serial.println(pin1state);
  Serial.print("\n");
}
