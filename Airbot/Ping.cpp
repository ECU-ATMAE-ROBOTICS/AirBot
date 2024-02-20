#include "Ping.h"


short getDistance(byte pin)
{
    long duration;
    short cm;

    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(2);
    digitalWrite(pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pin, LOW);

    pinMode(pin, INPUT);
    duration = pulseIn(pin, HIGH);
    
    return duration / 29 / 2;

}