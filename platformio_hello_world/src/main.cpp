#include <Arduino.h>
#define builtin_led 13

void setup() {
  pinMode(builtin_led, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  digitalWrite(builtin_led, HIGH);
  delay(3000);
  digitalWrite(builtin_led, LOW);
  delay(2000);
  Serial.println("Hello World");
  // put your main code here, to run repeatedly:
}
