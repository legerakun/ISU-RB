const int pinPhoto = A0;
int raw = 0;
#define LED_PIN_01 9

void setup () {
  Serial.begin(9600);
  pinMode(LED_PIN_01, OUTPUT);
  pinMode(pinPhoto, INPUT);
}

void loop () {
  int i;
  raw = analogRead(pinPhoto);
  Serial.println(raw);
  analogWrite(LED_PIN_01, raw);
  delay (100); // подождать 1 с   
}
