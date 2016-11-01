#include "sumo_AI.h"

/*A queue that will contain the actions that the robot will execute next.*/
QueueList <SumoAction> next_action;

/*This variable is set if ping-sesor detects an object.*/
bool ping_detection = false;

/*This variable contains the current state of the qtr-line-sensors.*/
int qtr_detection = NO_LINE;

/*This variable is set to the current angle of the servo at each iteration of the program loop.*/
int detection_angle = 0;

/*This variable is set to the current angle of the servo on each detection. 
 *It is then used to help the robot find the opponent if the robot loses track of it.*/
int prev_detection_angle = 0;

/*This variable is set to the current measured distance of the ping-sensor, at each iteration of the program loop.*/
int ping_dist = 0;

void start_sumo()
{ 
  setupAI();

  /*Main program loop...*/
  while(true)
  {
    sense();
    plan();
    act();
  }
}

void setupAI()
{
  Serial.begin(9600);
  configure_motors();
  setServoPos(90);
  next_action.push(SumoAction(FORWARD,1));
}

void sense()
{
  sweepServo();
  checkPing();
  checkQTRS();
}

void sweepServo()
{
  tickServo();
  detection_angle = getServoPos();
}

void checkPing()
{
  ping_dist = ping();
    
  if(ping_dist <= MAX_VALID_PING_DISTANCE_CM && ping_dist > MIN_VALID_PING_DISTANCE_CM)
  {
    ping_detection = true;
  }
  else
  {
    ping_detection = false;
  }
}

void checkQTRS()
{
  qtr_detection = readQTRSensors();
}

void plan()
{ 
  if(qtr_detection == NO_LINE)
  {
    if(ping_detection)
    {
      clearAllActions();
      
      if(detection_angle > (SERVO_MID_ANGLE + SERVO_DETECTION_OFFSET))
      {
        prev_detection_angle = detection_angle;
        setServoPos(70);
        next_action.push(SumoAction(LEFT,3));
      }
      else if(detection_angle < (SERVO_MID_ANGLE - SERVO_DETECTION_OFFSET))
      {
        prev_detection_angle = detection_angle;
        setServoPos(110);
        next_action.push(SumoAction(RIGHT,3));
      }
      else
      {
        next_action.push(SumoAction(FORWARD,1));
      }
    }
    else
    {
      if(next_action.isEmpty() && prev_detection_angle != SERVO_MID_ANGLE)
      {
        if(prev_detection_angle >= (SERVO_MID_ANGLE + SERVO_DETECTION_OFFSET))
        {
          next_action.push(SumoAction(LEFT,3));
        }
        else if( prev_detection_angle <= (SERVO_MID_ANGLE - SERVO_DETECTION_OFFSET))
        {
          next_action.push(SumoAction(RIGHT,3));
        }
        else
        {
          next_action.push(SumoAction(FORWARD,1));
        }
        
        prev_detection_angle = SERVO_MID_ANGLE;
      }
    }
  }
  else
  {
    if(ping_detection)
    {
      
    }
    else
    {
      
    }
  }

  if(!next_action.isEmpty())
  {
    int t = next_action.peek().type;
    
    switch(t)
    {
      case FORWARD: 
      Serial.print("GOING FORWARD. ");
      break;
      case BACKWARD:
      Serial.print("GOING BACKWARD. ");
      break;
      case LEFT:
      Serial.print("GOING LEFT. ");
      break;
      case RIGHT:
      Serial.print("GOING RIGHT. ");
      break;
      default:
      Serial.print("INVALID ACTION. ");
      break;
    }
  }
  
  Serial.print("PING ANGLE: ");
  Serial.print(detection_angle);
  Serial.print(" DIST: ");
  Serial.println(ping_dist);
}

void act()
{
  if(!next_action.isEmpty())
  {  
    performAction(next_action.peek().type, next_action.peek().iterations);
  }
  else
  {
    next_action.push(SumoAction(FORWARD,1));
  }
}

void performAction(int action_type, int action_iterator)
{
  switch(action_type)
  {
  case FORWARD:   
  moveForward();
  break;
  case BACKWARD:  
  moveBackward();
  break;
  case LEFT:
  rotateLeft();
  break;      
  case RIGHT:
  rotateRight();
  break;
  default:
  moveForward();
  break;     
  }

  next_action.peek().iterations --;

  if(next_action.peek().iterations < 1)
  {
    next_action.pop();
  }
}

void clearAllActions()
{
  while(!next_action.isEmpty())
  {
    next_action.pop();
  }

  Serial.println("Action-list is empty!");
}



//************************************************
//**    Optional tests are implemented below    **
//************************************************

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
  
  tickServo();

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
