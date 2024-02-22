#include "Ping.h"


short getDistance(byte pin)
{
    long duration;

    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(2);
    digitalWrite(pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pin, LOW);

    pinMode(pin, INPUT);
    duration = pulseIn(pin, HIGH);
    
    return duration / 74 / 2.0;
    
}