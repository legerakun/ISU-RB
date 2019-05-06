#define LED_PIN_01 9
#define LED_PIN_02 13

void setup () {
  pinMode (LED_PIN_01, OUTPUT);
  pinMode (LED_PIN_02, OUTPUT);
}

void loop () {
  int i;
   for(i = 0; i <= 255; i++){ 
    analogWrite(LED_PIN_01, i);
    digitalWrite (LED_PIN_02, HIGH); // включить светодиод
    delay (10); // подождать 1 с
    if(i==255){
      for(i = 255; i >= 0; i--){
        analogWrite(LED_PIN_01, i);
        digitalWrite (LED_PIN_02, LOW); // выключить светодиод
        delay (10); // подождать 1 с
      };
    };  
  };  
}
