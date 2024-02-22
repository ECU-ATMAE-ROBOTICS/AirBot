#include "Ping.h"
#include <SoftwareSerial.h>


SoftwareSerial LCD = SoftwareSerial(255,1);

// pin number of the sensor's output:
const int pingPin = 7;

// Pinged distance
short in;

// Range based on Parallax PING Datasheet
const short MAX_DISTANCE = 120;

void setup()
{
  // initialize serial communication:
  LCD.begin(9600);
  delay(1000);
}

void loop()
{
  in = getDistance(pingPin);

  //Clear LCD
  LCD.write(12);
  
  if (in < MAX_DISTANCE && in > 0)
  {
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

