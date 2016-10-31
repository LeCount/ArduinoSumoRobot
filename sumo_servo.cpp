#include "sumo_servo.h"
#include "sumo_ping.h"
/*Global servo variables. Variable are defined here.*/
int servo_pos = SERVO_MID_ANGLE;
Servo servo;

void setServoPos(int new_pos)
{
  if(!servo.attached())
  {
    servo.attach(SERVO_PIN); 
  }
  
  servo_pos = new_pos;
  servo.write(servo_pos);
  delay(100);
}

int getServoPos()
{
  return servo_pos;
}

void sweepServo(int dir)
{

  if(!servo.attached())
  {
    servo.attach(SERVO_PIN); 
    setServoPos(SERVO_MID_ANGLE);  
  }

  servo_pos = servo_pos + (SERVO_STEP_DEGREE * dir);

  if((servo_pos + SERVO_STEP_DEGREE) > SERVO_PRACTICAL_MAX_ANGLE && dir == 1)
  {
    
  }
  else if((servo_pos - SERVO_STEP_DEGREE) < SERVO_MIN_ANGLE && dir == -1)
  {
    
  }
  else
  {
    servo.write(servo_pos);
  }
}
