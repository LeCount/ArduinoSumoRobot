#include "sumo_servo.h"

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
}

int getServoPos()
{
  return servo_pos;
}

void sweepServo()
{
  if(!servo.attached())
  {
    servo.attach(SERVO_PIN); 
  }
  
  servo.write(SERVO_MID_ANGLE);
  delay(100);

  servo_pos = SERVO_MID_ANGLE;
  
  for(servo_pos = SERVO_MID_ANGLE; 
      servo_pos <= SERVO_MAX_ANGLE; 
      servo_pos += SERVO_STEP_DEGREE)
  {
    servo.write(servo_pos);
    delay(10);
  }
  
  for(servo_pos = SERVO_MAX_ANGLE; 
      servo_pos >= SERVO_MID_ANGLE; 
      servo_pos -= SERVO_STEP_DEGREE)
  {
    servo.write(servo_pos);
    delay(10);
  }
  
  for(servo_pos = SERVO_MID_ANGLE; 
      servo_pos <= SERVO_MIN_ANGLE; 
      servo_pos -= SERVO_STEP_DEGREE)
  {
    servo.write(servo_pos);
    delay(10);
  }
  
  for(servo_pos = SERVO_MIN_ANGLE; 
      servo_pos <= SERVO_MID_ANGLE; 
      servo_pos += SERVO_STEP_DEGREE)
  {
    servo.write(servo_pos);
    delay(10);
  }
}
