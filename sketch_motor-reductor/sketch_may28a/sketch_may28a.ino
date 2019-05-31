int IN3 = 5; 
int IN4 = 4;
int IN2 = 6; 
int IN1 = 7;

void setup()
{
  Serial.begin(9600);
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN1, OUTPUT);
}
void loop()
{
   char val = Serial.read();
  if (val == 119) 
    {
      digitalWrite (IN3, HIGH);
      digitalWrite (IN4, LOW);
      digitalWrite (IN1, HIGH);
      digitalWrite (IN2, LOW);
    }
   if (val == 115) 
    {
      digitalWrite (IN4, HIGH);
      digitalWrite (IN3, LOW);
      digitalWrite (IN2, HIGH);
      digitalWrite (IN1, LOW);
    } 
    if (val == 32) 
    {
      digitalWrite (IN3, LOW);
      digitalWrite (IN4, LOW);
      digitalWrite (IN2, LOW);
      digitalWrite (IN1, LOW);
    }   
  
 
  
  }
