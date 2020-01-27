#include <Servo.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

Servo myservo;

int compteurfm;
int nombreTour = 0;
int temps = 1;
unsigned long compte_temps;
float x;

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode (2,INPUT_PULLUP);
  attachInterrupt (0, anemometre, RISING);
  myservo.attach(4);
  myservo.write(0);
}

void loop()
{
  x = 2*3.1415*0.05*5*compteurfm/8;
  lcd.setCursor(4,1);
  lcd.print(x);
  lcd.println ("m/s          ");
  compteurfm = 0;
  delay(1000);
  lcd.clear();
}

void anemometre()
{
  compteurfm++;
  
  if(x>=11){
    myservo.write(90);
  }else{
    myservo.write(1);
  }
}

