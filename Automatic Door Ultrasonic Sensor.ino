const int Trigger = 2;
const int Echo = 3;
const int greenled = 9;
const int redled = 10;
#include <Servo.h>
Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT);

servo1.attach(5);
servo2.attach(6);

servo1.write(0);
servo2.write(0);

digitalWrite(greenled, LOW);
digitalWrite(redled, LOW);
}

void loop() {

long t;
long d;

digitalWrite(Trigger, HIGH);
  delayMicroseconds(60);
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH);
  d = t/59;

  Serial.println(d);

 if (d <50){
    digitalWrite(greenled, HIGH);
    servo1.write(90);
    servo2.write(90);
    delay(1000);
    servo1.write(0);
    servo2.write(0);
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);

  }else{
    digitalWrite(greenled, LOW); 
    digitalWrite(redled, HIGH);
    delay(100);
      digitalWrite(redled, LOW);
    
  }

  
  
}
