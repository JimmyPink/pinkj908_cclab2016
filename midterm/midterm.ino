 

  https://youtu.be/K4S0A0ajIWQ  // video of the thing working


#include <Servo.h>

Servo myServo;  
 
 
#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

int pos = 180;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);

  myServo.attach(9);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);
 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 10) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
  myServo.write(pos); // servo goes to low
}
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
    myServo.write(0);  // servo goe up
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
