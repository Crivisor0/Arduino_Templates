// Varibales
typedef struct
{
  short forwardPin;
  short backwardPin;
  short speedPin;
} motor;

motor motorA;  // right
motor motorB;  // left

short leftInfo[2][2] = { { 0, 0 }, { 0, 0 } };
short rightInfo[2][2] = { { 0, 0 }, { 0, 0 } };
// Prototypes
// Setup motors in void setup()
// Function Initialization
void moveTank(short leftSpeed, short rightSpeed) {
  leftInfo[1] = {
    abs(leftSpeed), ((leftSpeed >= 0) ? HIGH : LOW)
  };

  rightInfo[1] = {
    abs(rightSpeed), ((rightSpeed >= 0) ? HIGH : LOW)
  };
  // Use motor control way example on standard L298N
  if (rightInfo[0][1] != rightInfo[1][1]) {
    digitalWrite(motorA.forwardPin, rightInfo[1][1]);
    digitalWrite(motorA.backwardPin, !rightInfo[1][1]);  // Flip it to low if forward and to high if backward

    rightInfo[0][1] = rightInfo[1][1];
  }
  //
  if (leftInfo[0][1] != leftInfo[1][1]) {
    digitalWrite(motorB.forwardPin, leftInfo[1][1]);
    digitalWrite(motorB.backwardPin, !leftInfo[1][1]);  // Flip it to low if forward and to high if backward

    leftInfo[0][1] = leftInfo[1][1];
  }
  //
  if (rightInfo[0][0] != rightInfo[1][0]) {

    analogWrite(motorA.speedPin, rightInfo[1][0]);

    rightInfo[0][0] = rightInfo[1][0];
  }


  if (leftInfo[0][0] != leftInfo[1][0]) {

    analogWrite(motorB.speedPin, leftInfo[1][0]);

    leftInfo[0][0] = leftInfo[1][0];
  }
}
