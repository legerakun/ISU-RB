#include <Servo.h>
Servo servo;
#define TRIGGER_PIN 12
#define ECHO_PIN 11

void setup() {
  servo.attach(9);
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
} 

void loop() {  
  int i, j;
  if(i == 0){
    for(; i < 181; i++){
        servoMove(i);
    }
  }
  if(i = 180){
    for(i == 180; i >= 0; i--){
        servoMove(i);
    }  
  }
}

void servoMove(int a){
  int dur, dis;
        servo.write(a);
        digitalWrite(TRIGGER_PIN, LOW);
        delayMicroseconds(2);
    
        digitalWrite(TRIGGER_PIN, HIGH);
        delayMicroseconds(10);
    
        digitalWrite(TRIGGER_PIN, LOW);
        dur = pulseIn(ECHO_PIN, HIGH);
        dis = dur / 58;
    
        if(dis < 5){ // MUST BE 5cm
          Serial.println("ALARM, ITEM IS CLOSER THAN 5cm");
        }else{
          Serial.print(dis);
          Serial.println(" mm/");
        }
        delay(10); 
    
}  


