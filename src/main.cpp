#include <Arduino.h>
#include "../omega_motors.h"
#include "../omega_motors.cpp"


Motor motor;

void setup() {

  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);

  motor = Motor(PB4, PD6, &PORTC, &PORTD, 3);

  motor.setSpeed(255, FOWARD);

  digitalWrite(1, 0);
  analogWrite(1, 20);
}

void loop() {

}