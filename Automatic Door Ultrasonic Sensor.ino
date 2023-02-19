const int Trigger = 2; // Define Trigger pin
const int Echo = 3; // Define Echo pin
const int greenled = 9; // Define greenled pin
const int redled = 10; // Define redled pin
#include <Servo.h>
Servo servo1; // Add a servo object
Servo servo2; // Add a second servo object

void setup() {
  Serial.begin(9600); // Initialize Serial monitor 
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT);

  // attach servo objects to pins 5,6
servo1.attach(5); 
servo2.attach(6);

  // Set servos at 0
servo1.write(0);
servo2.write(0);

  // Turn off LEDs
digitalWrite(greenled, LOW);
digitalWrite(redled, LOW);
}

void loop() {

  // Add variables "t" for time and "d" for distance
long t;
long d;
  
digitalWrite(Trigger, HIGH);
  delayMicroseconds(60);
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH);
  d = t/59;

  Serial.println(d);

 if (d <50){ // Code runs if the distance is lower than 50cm
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
