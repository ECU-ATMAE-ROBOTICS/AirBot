#include "Servos.h"
#include "Ping.h"

/*void Oscillate(Servo motor, short *position, bool dir) {

  if (dir) {
    *position = *position + 20;
    motor.write(*position);
  } else {
    *position = *position - 20;
    motor.write(*position);
  }
}*/

void Open(Servo motor) {
  motor.write(100);
}

void Close(Servo motor) {
  motor.write(30);
}
