#include "SoftwareSerial.h"
#include "Ping.h"

void displayDistance(short distance, SoftwareSerial lcd){

  lcd.write(12);
  lcd.print(distance);
  lcd.print("in ");
  lcd.print(distance * 2.54);
  lcd.print("cm");
}

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
    
    return duration / 74 / 2;
}
