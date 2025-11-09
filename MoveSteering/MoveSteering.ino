typedef struct
{
  short forwardPin;
  short backwardPin;
  short speedPin;
} motor;

motor motorA;  // right
motor motorB;  // left

void moveSteering(short speed, short steer) {
  short leftSpeed =
    (abs(speed) - (steer * ((steer < 0) ? -1 : 0));

  short rightSpeed = 
    (abs(speed) - (steer * ((steer >= 0) ? 1 : 0));

  byte dir = (speed >= 0) ? HIGH : LOW;
  // Use motor control way example on standard L298N
  digitalWrite(motorA.forwardPin, dir);
  digitalWrite(motorA.backwardPin, !dir); // Flip it to low if forward and to high if backward
//
  digitalWrite(motorB.forwardPin, dir);
  digitalWrite(motorB.backwardPin, !dir); // Flip it to low if forward and to high if backward
//
  analogWrite(motorA.speedPin, rightSpeed);
  analogWrite(motorB.speedPin, leftSpeed);
}
