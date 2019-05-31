#include <Servo.h>
Servo servo;
#define TRIGGER_PIN 12
#define ECHO_PIN 11

void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
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
    
        if(dis < 5){// MUST BE 5cm
          digitalWrite(7,HIGH);
          Serial.println("ALARM, ITEM IS CLOSER THAN 5cm");
        }else{
          digitalWrite(7,LOW);
          Serial.print(dis);
          Serial.println(" cm/");
        }

        if(a == 0){
          digitalWrite(8,HIGH);
        }else{
          digitalWrite(8,LOW);
             if(a == 180){
                digitalWrite(8,HIGH);
             }
        }
   
        delay(10); 
    }  
