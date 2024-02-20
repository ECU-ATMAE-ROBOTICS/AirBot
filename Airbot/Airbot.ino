#include "Ping.h"
#include <SoftwareSerial.h>


SoftwareSerial LCD = SoftwareSerial(255,1);

// pin number of the sensor's output:
const int pingPin = 7;

// Pinged distance
short cm;

void setup()
{
  // initialize serial communication:
  LCD.begin(9600);
  delay(1000);
}

void loop()
{
  cm = getDistance(pingPin);

  displayDistance(cm);

  delay(500);
}

void displayDistance(short distance)
{
  LCD.write(12);

  LCD.print(distance);
  LCD.print("cm");
}
