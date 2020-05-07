#define BLYNK_PRINT Serial
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX

char auth[] = "2907701a4edb4b518fd52667fc298f66";

SoftwareSerial SerialBLE(10, 11); // RX, TX

int leftMotorForward = 5;//in3
int rightMotorForward = 7;//in1
int leftMotorBackward = 4;//in4
int rightMotorBackward = 6;//in2
int state =12;

int f1 = 2;
int b1 = 3;
int l1 = 8;
int r1 = 9;
int forward=0;
int backward=0;
int left=0;
int right=0;
int states=0;
void setup()
{
  // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
  pinMode(leftMotorForward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT); 
  pinMode(leftMotorBackward, OUTPUT);  
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(state, INPUT);
}

void loop()
{
  states=digitalRead(state);
  forward=digitalRead(f1);
  backward=digitalRead(b1);
  left=digitalRead(l1);
  right=digitalRead(r1);
  if(states==1){
  if(forward==1){
    MotorForward();
    forward=0;
  }
   else if(backward==1){
    MotorBackward();
    backward=0;
  }
   else if(left==1){
    TurnLeft();
    left=0;
  }
   else if(right==1){
    TurnRight();
    right=0;
  }
    else MotorStop();
  }
  else MotorStop();
  Blynk.run();
  delay(100);

}

void MotorForward(void)
{
  digitalWrite(leftMotorForward,HIGH);
  digitalWrite(rightMotorForward,HIGH);
  digitalWrite(leftMotorBackward,LOW);
  digitalWrite(rightMotorBackward,LOW);
}

void MotorBackward(void)
{
  digitalWrite(leftMotorBackward,HIGH);
  digitalWrite(rightMotorBackward,HIGH);
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(rightMotorForward,LOW);
}

void TurnLeft(void)   
{
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(rightMotorForward,HIGH);
  digitalWrite(rightMotorBackward,LOW);
  digitalWrite(leftMotorBackward,LOW);  
}

void TurnRight(void)   
{
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(rightMotorForward,LOW);
  digitalWrite(rightMotorBackward,HIGH);
  digitalWrite(leftMotorBackward,LOW);
}

void MotorStop(void)   
{
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(leftMotorBackward,LOW);
  digitalWrite(rightMotorForward,LOW);
  digitalWrite(rightMotorBackward,LOW);
}
