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
  for(int pos = 72; pos >= 0; pos--)
  {
    motor.write(pos);
    delay(15);
  }
}

void Close(Servo motor) {
  for(int pos = 0; pos <= 72; pos++)
  {
    motor.write(pos);
    delay(15);
  }
}
