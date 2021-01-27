#include "motor.h"
#include <HCSR04.h>

#define enb 5
#define in4 6
#define in3 7
#define in2 8
#define in1 9
#define ena 10
#define trig A0
#define echo A1

#define SensorRight A2
#define SensorLeft  A3
int SL;
int SR;
motor m(ena, enb, in4, in3, in2, in1);


//HCSR04 hc(trig,echo);//initialisation class HCSR04 (trig pin , echo pin)

void setup() {
  // put your setup code here, to run once:
//
Serial.begin(9600);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(ena,OUTPUT);
pinMode(enb,OUTPUT);  
pinMode(SensorRight, INPUT);
pinMode(SensorLeft, INPUT);

}

void loop() {
SR = digitalRead(SensorRight);
SL = digitalRead(SensorLeft);
if (SL ==LOW&&SR== LOW)
  m.avancer();   // go ahead
else if (SL == LOW & SR == HIGH)
  m.droite();
else if (SR == LOW & SL ==  HIGH)
  m.gauche();
else
  m.reculer();
}
 
