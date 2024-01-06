#include "Motor.h"

Motor right(11, 10, 20, 21);
Motor left(9, 8, 18, 19);

void setup(){
  
}

void loop(){
  for(int i=0;i<100;i++){
    left.rotate(i);
    right.rotate(i);
    delay(10);
  }
  delay(1000);
  for(int i=100;i>0;i--){
    left.rotate(i);
    right.rotate(i);
    delay(10);
  }
  delay(1000);
  for(int i=0;i>-100;i--){
    left.rotate(i);
    right.rotate(i);
    delay(10);
  }
  delay(1000);
  for(int i=-100;i<0;i++){
    left.rotate(i);
    right.rotate(i);
    delay(10);
  }
  delay(1000);
}
