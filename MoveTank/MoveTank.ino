// Varibales
typedef struct
{
  short forwardPin;
  short backwardPin;
  short speedPin;
} motor;

motor motorA; // right
motor motorB; // left
// Prototypes
void moveTank(short leftSpeed, short rightSpeed);
//
// Setup motors in void setup()  
// Function Initialization
void moveTank(short leftSpeed, short rightSpeed) {
    short leftInfo[2] = {
        abs(leftSpeed), ((leftSpeed >= 0) ? HIGH : LOW)
    };

    short rightInfo[2] = {
        abs(rightSpeed), ((rightSpeed >= 0) ? HIGH : LOW)
    };
  // Use motor control way example on standard L298N
  digitalWrite(motorA.forwardPin, rightInfo[1]);
  digitalWrite(motorA.backwardPin, !rightInfo[1]); // Flip it to low if forward and to high if backward
//
  digitalWrite(motorB.forwardPin, leftInfo[1]);
  digitalWrite(motorB.backwardPin, !leftInfo[1]); // Flip it to low if forward and to high if backward
//
  analogWrite(motorA.speedPin, rightSpeed);
  analogWrite(motorB.speedPin, leftSpeed);
}
