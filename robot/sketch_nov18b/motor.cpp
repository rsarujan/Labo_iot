#include "arduino.h"
#include "motor.h"

motor::motor(int pena, int penb, int pin4, int pin3, int pin2, int pin1){
  ena = pena;
  enb = penb;
  in4 = pin4;
  in3 = pin3;
  in2 = pin2;
  in1 = pin1;
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in1, OUTPUT);
}
motor::~motor(){

}

void motor::avancer(){

  digitalWrite(ena, HIGH);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(enb, HIGH);    // turn the LED on (HIGH is the voltage level)

  analogWrite(ena,vitesse/2);
  analogWrite(enb,vitesse/2);

  digitalWrite(in4, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(in3, LOW);    // turn the LED off by making the voltage LOW

  digitalWrite(in2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(in1, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(10);                // wait for a second
}
void motor::reculer(){
  digitalWrite(ena, HIGH);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(enb, HIGH);    // turn the LED on (HIGH is the voltage level)

  analogWrite(ena,vitesse);
  analogWrite(enb,vitesse);
  
  digitalWrite(in4, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(in3, HIGH);    // turn the LED off by making the voltage LOW

  digitalWrite(in2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(in1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);                // wait for a second
}
void motor::gauche(){
  digitalWrite(ena, HIGH);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(enb, HIGH);    // turn the LED on (HIGH is the voltage level)

  analogWrite(ena,vitesse/3);
  analogWrite(enb,vitesse/3);
  
  digitalWrite(in4, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(in3, LOW);    // turn the LED off by making the voltage LOW

  digitalWrite(in2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(in1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                // wait for a second
}
void motor::droite(){
  digitalWrite(ena, HIGH);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(enb, HIGH);    // turn the LED on (HIGH is the voltage level)

  analogWrite(ena,vitesse/5);
  analogWrite(enb,vitesse/5);
  
  digitalWrite(in4, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(in3, HIGH);    // turn the LED off by making the voltage LOW

  digitalWrite(in2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(in1, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(10);                // wait for a second
}
void motor::arret()
{
    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);
  
    digitalWrite(in4, LOW);
    digitalWrite(in3, LOW);

    digitalWrite(in2, LOW);
    digitalWrite(in1, LOW);
    delay(20);
}

