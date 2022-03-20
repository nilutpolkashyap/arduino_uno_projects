
const int button1 = 2;   
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;

const int red_led = 13;
const int green_led = 12;
const int blue_led = 11; 

byte ledState1 = LOW;
byte ledState2 = LOW;
byte ledState3 = LOW;
byte ledState4 = LOW;

byte state1 = LOW;
byte state2 = LOW;
byte state3 = LOW;
byte state4 = LOW;

byte lastButton1State = LOW;
byte lastButton2State = LOW;
byte lastButton3State = LOW;
byte lastButton4State = LOW;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);  

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  state1 = digitalRead(button1);
  state2 = digitalRead(button2);
  state3 = digitalRead(button3);
  state4 = digitalRead(button4);

  if(state1 == HIGH){
    ledState1 = !ledState1;
  }

  if(state2 == HIGH){
    ledState2 = !ledState2;  
  }

  if(state3 == HIGH){
    ledState3 = !ledState3;
  }

  if(state4 == HIGH){
    ledState1 = LOW;
    ledState2 = LOW;
    ledState3 = LOW;
  }


  if((ledState1 == HIGH) && (ledState2 == LOW) && (ledState3 == LOW)){
    digitalWrite(red_led, HIGH);
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, LOW);
  }

  else if((ledState1 == LOW) && (ledState2 == HIGH) && (ledState3 == LOW)){
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, HIGH);
    digitalWrite(blue_led, LOW);
  }

  else if((ledState1 == LOW) && (ledState2 == LOW) && (ledState3 == HIGH)){
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, HIGH);
  }

  else if((ledState1 == LOW) && (ledState2 == LOW) && (ledState3 == LOW)){
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, LOW);
  }

}
