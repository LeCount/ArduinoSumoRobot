#include "sumo_servo.h"
#include "sumo_ping.h"

Servo servo;
int servo_pos = SERVO_MID_ANGLE;
int servo_dir = 1; 

void configureServo()
{
  if(!servo.attached())
  {
    servo.attach(SERVO_PIN);
  }
}

void setServoPos(int new_pos)
{ 
  servo_pos = new_pos;
  servo.write(new_pos);
  delay(300);
}

int getServoPos()
{ 
  return servo_pos;
}

void tickServo()
{
  int temp_angle = 0;

  temp_angle = servo_pos + (45 * servo_dir);

  if(temp_angle > 180)
  {
    servo_dir = -1; 
  }
  else if(temp_angle < 0)
  {
    servo_dir = 1;
  }

  servo_pos = servo_pos + (45 * servo_dir);
  servo.write(servo_pos);
  delay(300);
}
