#include "sumo_test.h"

void testPing()
{
  Serial.println(ping());
  delay(100);
}

void testServo()
{
  setServoPos(90);
  Serial.print("Servo position: ");
  Serial.print(getServoPos());

  delay(500);

  setServoPos(180);
  Serial.print("Servo position: ");
  Serial.print(getServoPos());

  delay(500);

  setServoPos(90);
  Serial.print("Servo position: ");
  Serial.print(getServoPos());

  delay(500);

  setServoPos(0);
  Serial.print("Servo position: ");
  Serial.print(getServoPos());

  delay(500);

  setServoPos(90);
  Serial.print("Servo position: ");
  Serial.print(getServoPos());

  delay(500);
}

void testQTRSensors()
{
  Serial.print("QTR front: ");
  Serial.println(getQTRResultAsText(readQTRSensorsFront()));

  Serial.print("QTR back: ");
  Serial.println(getQTRResultAsText(readQTRSensorsBack()));
}

void testMotors()
{
  Serial.println("Moving forward...");
  moveForward();
  delay(5000);

  Serial.println("Moving backward...");
  moveBackward();
  delay(5000);
  
  Serial.println("Rotating left...");
  rotateLeft();
  delay(5000);

  Serial.println("Rotating right...");
  rotateRight();
  delay(5000);

  Serial.println("Turning left...");
  turnLeftForward();
  delay(5000);

  Serial.println("Turning right...");
  turnRightForward();
  delay(5000);

  Serial.println("Turning left (reverse)...");
  turnLeftBackward();
  delay(5000);  

  Serial.println("Turning right (reverse)...");
  turnRightBackward();
  delay(5000);
}

void testLED()
{
  int i = 0;
  
  Serial.println("LED will now blink for (about) 5 seconds...");
  
  for(i = 0; i < 40; i++)
  {
    blinkLED();
  }
}
