#include "Ping.h"
#include "Servos.h"

const int lcdPin = 1;
SoftwareSerial LCD = SoftwareSerial(255, lcdPin);

// pin number of the sensor's output:
const int pingPin = 7;

//Servo Pins
const int pingServoPin = 5, valveServoPin = 2;

//Servos
Servo pingServo;
Servo valveServo;

bool valveClosed = true;

// Pinged distance
short in;

// Range based on Parallax PING Datasheet
const short MAX_DISTANCE = 120;


void setup() {
  //Serial.begin(9600);
  LCD.begin(9600);

  // initialize serial communication:
  pingServo.attach(pingServoPin);
  valveServo.attach(valveServoPin);

  pingServo.write(30);
  Close(valveServo);

  LCD.write(12);
  LCD.print("HELLO :)");
  delay(2000);
  LCD.write(12);
  
}

void loop() {
  //Oscillates the servo
  for (int pos = 20; pos <= 160 && valveClosed; pos = pos + 1) {
    delay(20);
    pingServo.write(pos);
    if (pos % 10 == 0) {
      pingServo.detach();

      in = getDistance(pingPin);

      /*
      if(in < 6)
      {
        valveClosed = false;
      }
      */

      displayDistance(in, LCD);
      delay(5);
      pingServo.attach(pingServoPin);
    }
  }

  delay(50);

  for (int pos = 160; pos >= 30 && valveClosed; pos = pos - 1) {
    delay(20);
    pingServo.write(pos);
    if (pos % 10 == 0) {
      pingServo.detach();

      in = getDistance(pingPin);

      if(in < 6)
      {
        //valveClosed = false;
      }

      displayDistance(in, LCD);
      delay(5);
      pingServo.attach(pingServoPin);
    }
  }

  if (!valveClosed){
    pingServo.detach();
    Open(valveServo);
  }
  delay(50);
}
