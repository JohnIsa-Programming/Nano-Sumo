//import newping (better ultrasonic stuff)
#include "NewPing.h"
//ultrasonic variables-------------------------------------------------------
#define trigPin 12
#define echoPin 11

long duration;
int distance;

//IR sensor variables------------------------------------------------------
#define irFPin 4
#define irBPin 3

//motor variables-----------------------------------------------------------
//motor 1
#define ENA 10
#define IN1 9
#define IN2 8

//motor 2
#define ENB 5
#define IN3 7
#define IN4 6

NewPing sonar(trigPin,echoPin,40);
int Speed = 225;

void setup() {
  Serial.begin(9600); 
  //ultrasonic variables---------------------------------------------------
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  //IR sensor variabkles-------------------------------------------------
  pinMode(irFPin, INPUT);
  pinMode(irBPin, INPUT);
  //MOTOR---------------------------------------------------------------
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  delay(2000);
}

float ultrasonic(){
  int distance = sonar.ping_cm();
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}

bool irFSensor(){
  bool irFSensor = digitalRead(irFPin);

  return irFSensor;
}
bool irBSensor(){
  bool irBSensor = digitalRead(irBPin);

  return irBSensor;
}

void carRotate(){
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);

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
  
  int distance = ultrasonic();
  //create nested if statement make IR a priority if both detect black then continue with the created code below, if ir front detect white and ir back detect black then carBack, then viseversa.
   if(distance > 30){
     carRotate();
   }
   else if(distance <= 30){
     carForward();
   }
  


}