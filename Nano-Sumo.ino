//import newping (better ultrasonic stuff)
#include "NewPing.h"
//ultrasonic variables-------------------------------------------------------
#define trigPin 12
#define echoPin 11

long duration;
int distance;

//IR sensor variables------------------------------------------------------
#define irPinA 4
#define irPinB 3

//motor variables-----------------------------------------------------------
//motor 1
#define ENA 10
#define IN1 9
#define IN2 8

//motor 2
#define ENB 5
#define IN3 7
#define IN4 6

NewPing sonar(trigPin,echoPin,80);
int Speed = 255;

void setup() {
  Serial.begin(9600); 
  //ultrasonic variables---------------------------------------------------
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  //IR sensor variabkles-------------------------------------------------
  pinMode(irPinA, INPUT);
  pinMode(irPinB, INPUT);
  //pinMode(irBPin, INPUT);
  //MOTOR---------------------------------------------------------------
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  delay(5000);
}


void carRotate(){
  analogWrite(ENA, 130);
  analogWrite(ENB, 130);
  //left wheel
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //right wheel
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carForward(){
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);

  //left wheel
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //right wheel
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carBack(){
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);

  //left wheel
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //right wheel
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(500);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
void carFrontRecover(){
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);

  //left wheel
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //right wheel
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(500);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
void carStop(){
  //left wheel
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  //right wheel
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  
  int distance = sonar.ping_cm();
  int irstatusA = digitalRead(irPinA);
  int irstatusB = digitalRead(irPinB);
  Serial.println(distance);
  Serial.println(irstatusA);
  Serial.println(irstatusB);
  if(irstatusA == 0){
    Serial.println("Going Back");
    carBack();
  } else if(irstatusB == 0){
    Serial.println("Return to Arena!");
    carFrontRecover();
  }
   else if(distance <= 30 && distance != 0){
    Serial.println("Charge!!");
    carForward();
  } else {
    Serial.println("eSeeking");
    carRotate();
  }
  delay(20);

}