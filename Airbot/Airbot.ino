#include "Ping.h"
#include <SoftwareSerial.h>


SoftwareSerial LCD = SoftwareSerial(255,1);

// pin number of the sensor's output:
const int pingPin = 7;

// Pinged distance
short cm, in;

void setup()
{
  // initialize serial communication:
  LCD.begin(9600);
  delay(1000);
}

void loop()
{
  in = getDistance(pingPin);
  
  if (in <120 && in > 0)
  {
    LCD.write(12);

    LCD.print(in);
    LCD.print("in ");

    delay(500);
  }
  else{
    LCD.write(12);
    
    LCD.print("Out of range");
    delay(250);
  }
}

