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

void sweepServo()
{
   int d = 0;  

  if(!servo.attached())
  {
    servo.attach(SERVO_PIN); 
      setServoPos(SERVO_MID_ANGLE);  
  }
  

  
  for(servo_pos = SERVO_MID_ANGLE; 
      servo_pos <= SERVO_PRACTICAL_MAX_ANGLE; 
      servo_pos += SERVO_STEP_DEGREE)
  {
    servo.write(servo_pos);
    d = ping();
      if(d<MAX_VALID_PING_DISTANCE_CM && d > MIN_VALID_PING_DISTANCE_CM)
  { Serial.print("Detection at dist: ");
    Serial.print(d);  
    Serial.print(" cm, at angle: ");
    Serial.print(servo_pos);
    Serial.println(" degrees");
  }
    else
  {
    Serial.println("Ping...");
  }
    delay(SERVO_DELAY);
  }
  
  for(servo_pos = SERVO_PRACTICAL_MAX_ANGLE; 
      servo_pos >= SERVO_MID_ANGLE; 
      servo_pos -= SERVO_STEP_DEGREE)
  {
    servo.write(servo_pos);
    d = ping();
      if(d<MAX_VALID_PING_DISTANCE_CM && d > MIN_VALID_PING_DISTANCE_CM)
  { Serial.print("Detection at dist: ");
    Serial.print(d);  
    Serial.print(" cm, at angle: ");
    Serial.print(servo_pos);
    Serial.println(" degrees");
  }
  else
  {
    Serial.println("Ping...");
  }
    delay(SERVO_DELAY);
  }
  
  for(servo_pos = SERVO_MID_ANGLE; 
      servo_pos >= SERVO_MIN_ANGLE; 
      servo_pos -= SERVO_STEP_DEGREE)
  {
    servo.write(servo_pos);
    d = ping();
      if(d<MAX_VALID_PING_DISTANCE_CM && d > MIN_VALID_PING_DISTANCE_CM)
  { Serial.print("Detection at dist: ");
    Serial.print(d);  
    Serial.print(" cm, at angle: ");
    Serial.print(servo_pos);
    Serial.println(" degrees");
  }
    else
  {
    Serial.println("Ping...");
  }
   delay(SERVO_DELAY);
  }
  
  for(servo_pos = SERVO_MIN_ANGLE; 
      servo_pos <= SERVO_MID_ANGLE; 
      servo_pos += SERVO_STEP_DEGREE)
  {
    servo.write(servo_pos);
    d = ping();
      if(d<MAX_VALID_PING_DISTANCE_CM && d > MIN_VALID_PING_DISTANCE_CM)
  { Serial.print("Detection at dist: ");
    Serial.print(d);  
    Serial.print(" cm, at angle: ");
    Serial.print(servo_pos);
    Serial.println(" degrees");
  }
    else
  {
    Serial.println("Ping...");
  }
    delay(SERVO_DELAY);
  }
}
