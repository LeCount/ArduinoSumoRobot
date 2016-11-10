#include "exampleAI.h"

int turn_counter = 0;
int current_state = START_STATE;

volatile int ping_dist = -1;
volatile bool ping_state = false;
volatile int detection_angle = 90;
volatile int blink_count = 0;
volatile int qtr_situation = NO_LINE;
volatile bool qtr_state = false;

void setupAI()
{
  configureMotors();
  configureServo(); 
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void start_sumo()
{ 
  setupAI();

  /*Main loop.*/
  while(true)
  {
    switch(current_state)
    {
    case START_STATE:  
     
    MsTimer2::set(900, LEDCallback);
    MsTimer2::start();
    
    setServoPos(SERVO_MID_ANGLE); 
    sweepServo();
    setServoPos(SERVO_MID_ANGLE);  

    while(blink_count < 4)
    {
      //wait for interrupt
    }
    
    MsTimer2::stop();
    
    if(detection_angle > 90)
    {
      current_state = TURN_STATE; 
      rotateLeft();       
    }  
    else if(detection_angle < 90)
    {
      current_state = TURN_STATE;  
      rotateRight();    
    }  
    else
    {
      current_state = MOVE_F_STATE;    
      moveForward();  
    }   
    break;
    
    case MOVE_F_STATE:  
    
    digitalWrite(LED_PIN, LOW);
    MsTimer2::set(200, qtrCallbackFront);
    MsTimer2::start();
    
    while(current_state == MOVE_F_STATE)
    {     
      if(checkPing())
      {
        MsTimer2::stop();
        digitalWrite(LED_PIN, HIGH);
        ping_state = false;     
        qtr_state = false;   
        
        if(detection_angle > SERVO_MID_ANGLE)
        {
          current_state = TURN_STATE;
          stopMotors();
          turnRightForward();
        }
        else if(detection_angle < SERVO_MID_ANGLE)
        {
          current_state = TURN_STATE;
          stopMotors();
          turnLeftForward();
        }
        break;
      }
      
      if(qtr_state)
      { 
        MsTimer2::stop();
        ping_state = false;     
        qtr_state = false; 
        current_state = AVOID_LINE_STATE;
        break;
      }
      
      tickServo();
      digitalWrite(LED_PIN, LOW);
    }
    
    MsTimer2::stop();
    
    break;
           
    case TURN_STATE:
    
    MsTimer2::set(200, pingCallback);
    MsTimer2::start();

    setServoPos(SERVO_MID_ANGLE); 
    turn_counter = 0;
    
    while(turn_counter < 250)
    {
      if(checkQTR(1))
      {
        MsTimer2::stop();
        break;
      }
      if(ping_state)
      {
        MsTimer2::stop();
        digitalWrite(LED_PIN, HIGH);
        break;
      }

      turn_counter ++;
    }
    
    MsTimer2::stop();
    
    stopMotors();

    if(qtr_state)
    {
      ping_state = false;
      qtr_state = false;
      current_state = AVOID_LINE_STATE;
      break;
    }
    else if(ping_state)
    {
      ping_state = false;
      qtr_state = false;
      detection_angle = SERVO_MID_ANGLE;
      current_state = MOVE_F_STATE;
      moveForward();
      break;
    }
    else
    {
      ping_state = false;
      qtr_state = false;
      detection_angle = SERVO_MID_ANGLE;
      current_state = MOVE_F_STATE;
      moveForward();
      break;
    }

    case AVOID_LINE_STATE:
    
    qtr_situation = NO_LINE;
    MsTimer2::set(100, qtrCallbackBack);
    moveBackward();
    delay(600);
    MsTimer2::stop();

    if(qtr_state)
    {
      qtr_state = false;
      qtr_situation = NO_LINE;  
    }
    
    MsTimer2::set(100, qtrCallbackFront);
    rotateLeft();
    delay(600);
    MsTimer2::stop();

    if(qtr_state)
    {
      qtr_state = false;
      qtr_situation = NO_LINE;  
    }
    
    moveForward();
    current_state = MOVE_F_STATE;
    
    break;   
    }
  }
}

void LEDCallback()
{
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);

  blink_count = blink_count + 1;
}

void qtrCallbackFront()
{
  if(!qtr_state)
  {
    qtr_situation = readQTRSensorsFront();
    if(qtr_situation != NO_LINE)
    {
      qtr_state = true;
      stopMotors();
    } 
  }
}

void qtrCallbackBack()
{
  if(!qtr_state)
  {
    qtr_situation = readQTRSensorsBack();
    if(qtr_situation != NO_LINE)
    {
      qtr_state = true;
      stopMotors();
    } 
  }
}

void pingCallback()
{
  if(!ping_state)
  {
    ping_dist = ping();
    if(ping_dist > 0 && ping_dist <= MAX_VALID_PING_DISTANCE_CM )
    {
      stopMotors();
      ping_state = true;
      detection_angle = getServoPos(); 
    }
  }
}

void sweepServo()
{
  int angle = 90;
  
  for (angle = 90; angle <= 180; angle += 90) 
  { 
    setServoPos(angle);    
    checkPing();                              
  }
  for (angle = 180; angle >= 90; angle -= 90) 
  { 
    setServoPos(angle);      
    checkPing();                              
  }
  for (angle = 90; angle >= 0; angle -= 90) 
  {
    setServoPos(angle);        
    checkPing();   
  }
  for (angle = 0; angle <= 90; angle += 90)
  {
    setServoPos(angle);      
    checkPing();                                     
  } 
}

bool checkPing()
{
  if(!ping_state)
  {
    ping_dist = ping();
  
    if(ping_dist > 0 && ping_dist <= MAX_VALID_PING_DISTANCE_CM )
    {
      ping_state = true;
      detection_angle = getServoPos();
    }
  }
  
  return ping_state;
}

bool checkQTR(int dir)
{
  if(!qtr_state)
  {
    if(dir == 1)
    {
      qtr_situation = readQTRSensorsFront();
    }
    else
    {
      qtr_situation = readQTRSensorsBack();
    }
    if(qtr_situation != NO_LINE)
    {
      qtr_state = true;
    }
  }
  
  return qtr_state;
}

