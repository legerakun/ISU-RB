#define TRIGGER_PIN 10
#define ECHO_PIN 11

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
} 

void loop() {  
  int dur, dis;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIGGER_PIN, LOW);
  dur = pulseIn(ECHO_PIN, HIGH);
  dis = dur / 58;

  Serial.print(dis);
  Serial.println(" cm");
  delay(100);
}

