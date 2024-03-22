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

void Close(Servo motor) {
  for(int pos = 65; pos <= 75; pos++)
  {
    motor.write(pos);
    delay(20);
  }
}
