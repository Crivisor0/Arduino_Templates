struct motor_t {
  unsigned char forwardPin;
  unsigned char backwardPin;
  unsigned char speedPin;
};

motor_t motorR;  // right
motor_t motorL;  // left

short lastSpeed = 0;
short lastSteer = 0;

void moveSteering(short speed, short steer) {
  if (speed != lastSpeed || steer != lastSteer) {
    digitalWrite(motorL.forwardPin, speed >= 0);
    digitalWrite(motorR.forwardPin, speed >= 0);

    digitalWrite(motorL.backwardPin, speed < 0);
    digitalWrite(motorR.backwardPin, speed < 0);

    analogWrite(motorL.speedPin, abs(speed) - (steer * ((steer < 0) ? -1 : 0)));
    analogWrite(motorR.speedPin, abs(speed) - (steer * ((steer >= 0) ? 1 : 0)));

    lastSpeed = speed;
    lastSteer = steer;
  }
}
