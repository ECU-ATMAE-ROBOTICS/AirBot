#include "Ping.h"
#include "Servos.h"
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial LCD = SoftwareSerial(255, 1);

// pin number of the sensor's output:
const int pingPin = 7;

//Servo Pins
const int pingServoPin = 5, valveServoPin = 9;

//Servos
Servo pingServo;
Servo valveServo;



bool isClosed = true;

// Pinged distance
short in, cm;

// Range based on Parallax PING Datasheet
const short MAX_DISTANCE = 120;


void setup() {
  // initialize serial communication:
  pingServo.attach(pingServoPin);
  valveServo.attach(valveServoPin);

  //Initializing servo positions
  pingServo.write(180);
  Close(valveServo);

  Serial.begin(9600);
  LCD.begin(9600);
  delay(1000);
}

void loop() {

  //Test & replace code

  //Rotates the ping servo to 0 degrees
  for (int pos = 0; pos <= 180 && isClosed; pos += 1) {
    in = getDistance(pingPin);
    displayDistance(in, LCD);

    if (in < 4) {
      Open(pingServo);
      isClosed = !isClosed;
      break;
    }

    pingServo.write(pos);
    delay(15);
  }
  //Rotates the ping servo to 180 degrees
  for (int pos = 180; pos >= 0 && isClosed; pos -= 1) {
    in = getDistance(pingPin);
    displayDistance(in, LCD);

    if (in < 4) {
      Open(pingServo);
      isClosed = !isClosed;
      break;
    }

    pingServo.write(pos);
    delay(15);
  }

  if(!isClosed){
    delay(3000);
    Close(valveServo);
  }
}
