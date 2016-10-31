#include "sumo_AI.h"

int ping_distance_cm = 0;
int servo_angle = 90;
int line_situation = NO_LINE;

ThreadController thread_controller;
//PingThread ping_thread;
//ServoThread servo_thread;
//QTRThread qtr_thread;
// ThreadController that will controll all threads
ThreadController controll = ThreadController();

//My Thread (as a pointer)
Thread* myThread = new Thread();
Thread* myThread2 = new Thread();
Thread* myThread3 = new Thread();
Thread* myThread4 = new Thread();
//His Thread (not pointer)
Thread hisThread = Thread();

// callback for myThread
void sweep(){
  sweepServo();
}
void driveF(){
  moveForward();
}


void driveB(){
  moveBackward();
}

void start_sumo()
{
  // Configure myThread
  myThread->onRun(sweep);
  myThread->setInterval(1);

    myThread2->onRun(driveF);
  myThread2->setInterval(1);

    myThread3->onRun(driveB);
  myThread3->setInterval(1);

  // Adds both threads to the controller
  controll.add(myThread);
  controll.add(myThread2);
  controll.add(myThread3);
  
  while(true)
  {
   controll.run();
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
  //ping_thread = PingThread();
  //servo_thread = ServoThread();
  //qtr_thread = QTRThread();

  //ping_thread.setInterval(50);
  //servo_thread.setInterval(1000);
  //qtr_thread.setInterval(50);
  
  thread_controller = ThreadController();
  
  //thread_controller.add(&ping_thread);
  //thread_controller.add(&servo_thread);
  //thread_controller.add(&qtr_thread);
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
  /*
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
  */ 
  sweepServo();

 // Serial.println(); 

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
}
