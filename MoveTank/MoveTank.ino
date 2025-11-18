// Varibales
typedef struct
{
  short forwardPin;
  short backwardPin;
  short speedPin;
} motor;

motor motorR;  // right
motor motorL;  // left

short lastLeftSpeed = 0;
short lastRightSpeed = 0;
// Prototypes
// Setup motors in void setup()
// Function Initialization
void moveTank(short leftSpeed, short rightSpeed) {
  if (leftSpeed != lastLeftSpeed) {
    digitalWrite(motorL.forwardPin, leftSpeed >= 0);
    digitalWrite(motorL.backwardPin, leftSpeed < 0);

    analogWrite(motorL.speedPin, abs(leftSpeed));
    lastLeftSpeed = leftSpeed;
  }

  if (rightSpeed != lastRightSpeed) {

    digitalWrite(motorR.forwardPin, rightSpeed >= 0);
    digitalWrite(motorR.backwardPin, rightSpeed < 0);

    analogWrite(motorR.speedPin, abs(rightSpeed));
    lastRightSpeed = rightSpeed;
  }
}
