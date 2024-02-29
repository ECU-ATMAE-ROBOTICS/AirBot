#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Servo.h>

//void Oscillate(Servo motor, short *position, bool dir);
void Open(Servo motor);
void Close(Servo motor);

#endif 

