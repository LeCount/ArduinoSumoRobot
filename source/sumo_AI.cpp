#include "sumo_AI.h"

void start()
{
  /*This is all the code you need in order to understand how to control 
   * the electronics. Try these functions out in order to make sure they are configured properly.
   */
   
//  testPing();
//  testServo();
//  testQTRSensors();
//  testMotors();  
    
  while(true)
  {
    sense();
    plan();
    act();
  }
}

void sense()
{
      //Put your AMAZING AI-code here!
}

void plan()
{
      //Put your AMAZING AI-code here!
}

void act()
{
      //Put your AMAZING AI-code here!
}

void testPing()
{
  Serial.println("Testing ping-sensor...");
  
  int cm = ping();

  Serial.print("Distance to object: ");
  Serial.println(cm);  
  
  Serial.println();  
  
  delay(1000);
}

void testServo()
{
  Serial.println("Testing servo...");
  
  int servo_position1 = getServoPos();
  int servo_position2 = 0;

  Serial.println("Turning servo to 45 degrees..."); 
  setServoPos(45);
  
  Serial.println("Turning servo to 130 degrees..."); 
  setServoPos(130);

  Serial.print("Servo position is "); 
  servo_position2 = getServoPos();
  Serial.println(servo_position2); 
  
  Serial.println("Sweeping servo..."); 
  sweepServo();

  Serial.println(); 
  
  delay(1000);
}

void testQTRSensors()
{
  Serial.println("Testing QTR-sensors...");
  
  int result = readQTRSensors();
    
  switch(result)
  {
    case LINE_F_LEFT:
    Serial.println("Line detected at front-left!");
    break;
    case LINE_F_RIGHT:
    Serial.println("Line detected at front-right!");
    break;
    case LINE_B_LEFT:
    Serial.println("Line detected at rear-left!");
    break;
    case LINE_B_RIGHT:
    Serial.println("Line detected at rear-right!");
    break;
    case LINE_FRONT:
    Serial.println("Line detected at front!");
    break;
    case LINE_BACK: 
    Serial.println("Line detected at rear!");
    break;
    case LINE_INVALID:
    default:
    Serial.println("No line detected.");
    break;
  }

  Serial.println();

  delay(1000);
}

void testMotors()
{
  Serial.println("Testing motors...");

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

  Serial.println("Moving forward, and turning left...");
  turnLeftForward();
  delay(5000);

  Serial.println("Moving forward, and turning right...");
  turnRightForward();
  delay(5000);

  Serial.println("Moving backward, and turning left...");
  turnLeftBackward();
  delay(5000);  

  Serial.println("Moving backward, and turning right...");
  turnRightBackward();
  delay(5000);

  Serial.println();
  delay(1000);
}
