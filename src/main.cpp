#include <Arduino.h>
#include "omega_motors.h"
#include "omega_motors.cpp"

Motor motor1(PB4, PD6, 3, &PORTB, &PORTD, &DDRB, &DDRD);

void setup() {

}

void loop() {
  motor1.setSpeed(255, FOWARD);

  delay(500);

  motor1.setSpeed(255, BACKWARD);

  delay(500);

  motor1.setSpeed(0, STOP);

  delay(500);

  motor1.setSpeed(0, STOP_HOLDING);

  delay(500);

}