#include "sumo_servo.h"
#include "sumo_ping.h"

int servo_pos = SERVO_MID_ANGLE;
int servo_direction = 1;
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

int getServoPos(){return servo_pos;}

void tickServo()
{
  int next_servo_angle = 0;
  
  if(!servo.attached())
  {
    servo.attach(SERVO_PIN); 
    setServoPos(SERVO_MID_ANGLE);  
    delay(100);
  }

  next_servo_angle = servo_pos + (SERVO_STEP_DEGREE * servo_direction);

  if(next_servo_angle > SERVO_PRACTICAL_MAX_ANGLE && servo_direction == 1)
  {
    Serial.println("Servo dir = 1");
    servo_direction = -1;
    servo_pos = servo_pos - SERVO_STEP_DEGREE;
  }
  else if(next_servo_angle < SERVO_MIN_ANGLE && servo_direction == -1)
  {
    Serial.println("Servo dir = -1");
    servo_direction = 1;
    servo_pos = servo_pos + SERVO_STEP_DEGREE;
  }
  else
  {
    servo_pos = next_servo_angle;
  }

  servo.write(servo_pos);
}
