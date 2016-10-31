#include "sumo_AI.h"

/*A queue that will contain the states actions that the robot will execute next.*/
//QueueList <SumoAction> next_action;

/*This variable sets the servo to rotate left or right.*/
int servo_direction = 0;

/*This variable is set if ping-sesor detects an object.*/
bool ping_state = false;

/*This variable contains the current state of the qtr-line-sensors.*/
int qtr_state = NO_LINE;

void start_sumo()
{ 
  while(true)
  {
    testMotors();
  }
}

void sense()
{
  
}

void plan()
{

}

void act()
{

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
  setServoPos(90);
  delay(1000);
  setServoPos(90);
  

  delay(1000);
  
  Serial.println("Turning servo to 130 degrees..."); 
  setServoPos(130);

  delay(1000);

  Serial.print("Servo position is "); 
  servo_position2 = getServoPos();
  Serial.println(servo_position2); 

  Serial.println("Sweeping servo...");   
  
  sweepServo();

  Serial.println(); 

}

void testQTRSensors()
{ 
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
    case NO_LINE:
    Serial.println("No line detected.");
    break;
    default:
    Serial.println("No line detected.");
    break;
  }
  delay(500);
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
}
