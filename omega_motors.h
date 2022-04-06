#ifndef OMEGA_MOTORS_H
#define OMEGA_MOTORS_H

#include <Arduino.h>

typedef enum {
    FOWARD,
    BACKWARD,
    STOP,
    STOP_HOLDING
} Directions;

 class Motor
 {
    public:
        Motor(
            byte bitInA,
            byte bitInB,
            volatile uint8_t* portInA,
            volatile uint8_t* portInB,
            byte enable
        );
    void setSpeed(uint8_t speed, Directions direction);


    private:
        byte _bitInA, _bitInB, _enable;
        volatile uint8_t* _portInA; 
        volatile uint8_t* _portInB;

 };

#endif