#include "sumo_AI.h"

int ping_distance_cm = 0;
int servo_angle = 90;
int line_situation = NO_LINE;

class ServoThread: public Thread
{
  void run()
  {
    while(true)
    {
      sweepServo();
    }
  }
};

class PingThread: public Thread
{
  void run()
  {
    int temp_ping_distance = 0;
    
    while(true)
    {
      temp_ping_distance = ping();
      
      if(temp_ping_distance > MIN_VALID_PING_DISTANCE_CM && temp_ping_distance <= MAX_VALID_PING_DISTANCE_CM)
      {
        ping_distance_cm = temp_ping_distance;
      
        if(servo_angle == SERVO_MID_ANGLE)
        {
          servo_angle = getServoPos();
        }
      }
    }
  }
};

class QTRThread: public Thread
{
  void run()
  {
    while(true)
    {
      line_situation = readQTRSensors();
    }
  }
};

ThreadController thread_controller;
PingThread ping_thread;
ServoThread servo_thread;
QTRThread qtr_thread;

void start()
{
  /*This is all the code you need in order to understand how to control 
   * the electronics. Try these functions out in order to make sure they are configured properly.
   */
   
//  testPing();
//  testServo();
//  testQTRSensors();
//  testMotors();  

  startSensorThreads();
    
  while(true)
  {

//    plan();
//    act();
  }
}

void plan()
{
      //Put your AMAZING AI-code here!
}

void act()
{
      //Put your AMAZING AI-code here!
}

void startSensorThreads()
{
  ping_thread = PingThread();
  servo_thread = ServoThread();
  qtr_thread = QTRThread();

  ping_thread.setInterval(50);
  servo_thread.setInterval(50);
  qtr_thread.setInterval(50);
  
  thread_controller = ThreadController();
  
  thread_controller.add(&ping_thread);
  thread_controller.add(&servo_thread);
  thread_controller.add(&qtr_thread);

  Timer1.initialize(20000);
  Timer1.attachInterrupt(timerCallback);
  Timer1.start();
}

void timerCallback()
{
  thread_controller.run();
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
    case NO_LINE:
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
