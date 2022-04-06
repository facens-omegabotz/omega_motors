
#include <Arduino.h>

#include "omega_motors.h"

Motor::Motor(
            byte bitInA,
            byte bitInB,
            byte enable,
            volatile uint8_t* portInA,
            volatile uint8_t* portInB,
            volatile uint8_t* ddrInA,
            volatile uint8_t* ddrInB            
        )
{
    _bitInA = bitInA;
    _bitInB = bitInB;
    _portInA = portInA;
    _portInB = portInB;
    _enable = enable;

    *ddrInA |= (1 << _bitInA);
    *ddrInB |= (1 << _bitInB);
}

void Motor::setSpeed(uint8_t speed, Directions direction)
{
    switch (direction)
    {
    case FOWARD:
        *_portInA |= (1 << _bitInA);
        *_portInB &= ~(1 << _bitInB);
        analogWrite(_enable, speed);
        break;

    case BACKWARD:
        *_portInA &= ~(1 << _bitInA);
        *_portInB |= (1 << _bitInB);
        analogWrite(_enable, speed);
        break;

    case STOP: 
        *_portInA &= ~(1 << _bitInA);
        *_portInB &= ~(1 << _bitInB);
        analogWrite(_enable, 255);
        break;

    case STOP_HOLDING:
        *_portInA |= (1 << _bitInA);
        *_portInB |= (1 << _bitInB);
        analogWrite(_enable, 0);
        break;
        
    default:
        break;
    }
}
