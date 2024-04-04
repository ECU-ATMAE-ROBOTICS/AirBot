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
  //valveServo.write(75);
  Close(valveServo);

  delay(100);

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
  //Turn servo to the left slowly

  finished = false;

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


  //Change servo to the right slowly
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
    
    valveServo.write(0);
    finished = true;
    delay(160);
    
    Close(valveServo);
    delay(300);
    valveServo.detach();
    valveClosed = true;
  }
  delay(50);
}
