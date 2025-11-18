struct motor_t {
  unsigned char forwardPin;
  unsigned char backwardPin;
  unsigned char speedPin;
};

motor_t motorA;  // right
motor_t motorB;  // left

unsigned char lastDir = LOW;
short leftSpeed[2] = { 0, 0 };
short rightSpeed[2] = { 0, 0 };

void moveSteering(short speed, short steer) {
  leftSpeed[1] = (abs(speed) - (steer * ((steer < 0) ? -1 : 0));

  rightSpeed[1] =(abs(speed) - (steer * ((steer >= 0) ? 1 : 0));

  unsigned char dir = (speed >= 0) ? HIGH : LOW;
  // Use motor control way example on standard L298N
  if (dir != lastDir) {
    digitalWrite(motorA.forwardPin, dir);
    digitalWrite(motorA.backwardPin, !dir);  // Flip it to low if forward and to high if backward
                                             //
    digitalWrite(motorB.forwardPin, dir);
    digitalWrite(motorB.backwardPin, !dir);  // Flip it to low if forward and to high if backward
    //
    lastDir = dir;
  }
  //
  if (leftSpeed[0] != leftSpeed[1]) {
    analogWrite(motorB.speedPin, rightSpeed);
    leftSPeed[0] = leftSpeed[1];
  }
  if (rightSpeed[0] != rightSpeed[1]) {
    analogWrite(motorA.speedPin, rightSpeed);
    rightSpeed[0] = rightSpeed[1];
  }
}
