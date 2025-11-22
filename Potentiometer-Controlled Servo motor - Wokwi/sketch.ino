#include <Servo.h>
const int br = 9600;
const int servoPin = 11;
float servoAngle;
Servo myServo; 
int dt = 100;
const int pot = A5;
int potVal;
float input;

void setup() {
  Serial.begin(br);
  myServo.attach(servoPin);
  pinMode(pot, INPUT);
} 

void loop() {
  potVal = analogRead(pot);
  servoAngle = (180./1023.) * potVal ;
  Serial.println(servoAngle);
  myServo.write(servoAngle);
  delay(dt);
}