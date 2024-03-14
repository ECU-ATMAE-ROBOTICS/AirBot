#ifndef PING_H
#define PING_H

#include <Arduino.h>
#include <SoftwareSerial.h>

//short getDistance(byte pin);
void displayDistance(short distance, SoftwareSerial lcd);
short getDistance(byte pin);
bool verifyDistance(short distance);

#endif