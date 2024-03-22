#include "Ping.h"
#include "Servos.h"

const int lcdPin = 1;
SoftwareSerial LCD = SoftwareSerial(255, lcdPin);

// pin number of the sensor's output:
const int pingPin = 7;

//Servo Pins
const int pingServoPin = 5, valveServoPin = 3;

//Servos
Servo pingServo;
Servo valveServo;

bool valveClosed = true, finished = false;

// Pinged distance
short in;

// Range based on Parallax PING Datasheet
const short MAX_DISTANCE = 120;


void setup() {

  // Setting up servos
  pingServo.attach(pingServoPin);
  pingServo.write(30);

  valveServo.attach(valveServoPin);
  Close(valveServo);
  valveServo.detach();

  delay(15);

  //Initializing LCD
  LCD.begin(9600);

  LCD.write(12);
  LCD.print("HELLO :)");
  delay(2000);
  LCD.write(12);
  
}

void loop() {
  //Oscillates the servo
  for (int pos = 30; pos <= 160 && valveClosed; pos = pos + 1) {
    delay(15);
    pingServo.write(pos);
    if (pos % 10 == 0) {
      pingServo.detach();

      delay(25);

      in = getDistance(pingPin);
      
      if (in <6){
        valveClosed = false;
      }

      displayDistance(in, LCD);
      delay(10);
      pingServo.attach(pingServoPin);
    }
  }

  delay(50);

  for (int pos = 160; pos >= 30 && valveClosed; pos = pos- 1) {
    delay(15);
    pingServo.write(pos);
    if (pos % 10 == 0) {
      pingServo.detach();

      delay(25);

      in = getDistance(pingPin);

      if (in <6){
        valveClosed = false;
      }

      displayDistance(in, LCD);
      delay(10);
      pingServo.attach(pingServoPin);
    }
  }


  //Activate Valve Servo
  if (!valveClosed && !finished){
    valveServo.attach(valveServoPin);
    //delay();
    Open(valveServo);
    //valveServo.write(70);
    finished = true;
  }
  delay(50);
}
