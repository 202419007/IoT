//week02
// Arduino을 이용해서 밑에 코드를 짜서 LED와 초음파센서를 사용함

// C++ code
//

#define TRIG 13
#define ECHO 12

int led_R = 7;
void setup()
{
  Serial.begin(9600);
  pinMode(led_R, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{
  long duration, distance;
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn(ECHO, HIGH);
  distance = duration / 58.2;
  
  Serial.print(distance);
  Serial.println(" Cm");
  delay(1000);
  
 
  if(distance >= 100)
  {
    digitalWrite(led_R, HIGH);
    digitalWrite(8, LOW);
  }
  else
  {
    digitalWrite(led_R, LOW);
    digitalWrite(8, HIGH);
  }
  delay(1000);
    
  
  /*
  digitalWrite(led_R, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(led_R, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8, LOW);
  delay(1000);
  */
}
