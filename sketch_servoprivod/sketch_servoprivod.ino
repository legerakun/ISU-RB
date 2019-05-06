#include <Servo.h>
Servo servo;

void setup () {
  servo.attach(9);
  //servo.writeMicroseconds(2000);
}

void loop () {
  int i;
  for(i = 1; i > 0; i++){
    servo.write(i);
    delay(10);
      if(i == 180){
        for(i = 180; i <= 180; i--){
          servo.write(i);
          delay(10);
        }  
      }  
    }
  };  
