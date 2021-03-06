#include "sumo_motor_driver.h"

void configureMotors() 
{
  pinMode(MOTOR1_A_PIN, OUTPUT);
  pinMode(MOTOR1_B_PIN, OUTPUT);
  pinMode(MOTOR2_A_PIN, OUTPUT);
  pinMode(MOTOR2_B_PIN, OUTPUT);
}

void stopMotors()
{
  analogWrite(MOTOR1_A_PIN, 0);
  analogWrite(MOTOR1_B_PIN, 0);
  
  analogWrite(MOTOR2_A_PIN, 0);
  analogWrite(MOTOR2_B_PIN, 0);
  delay(10);
}

void moveForward()
{ 
  analogWrite(MOTOR1_A_PIN, 0);
  analogWrite(MOTOR1_B_PIN, MAX_MOTOR_SPEED);
  
  analogWrite(MOTOR2_A_PIN, MAX_MOTOR_SPEED);
  analogWrite(MOTOR2_B_PIN, 0);
}

void moveBackward()
{
  stopMotors();
  
  analogWrite(MOTOR1_A_PIN, MAX_MOTOR_SPEED);
  analogWrite(MOTOR1_B_PIN, 0);
  
  analogWrite(MOTOR2_A_PIN, 0);
  analogWrite(MOTOR2_B_PIN, MAX_MOTOR_SPEED);
}

void rotateLeft()
{
  stopMotors();
  
  analogWrite(MOTOR1_A_PIN, MAX_MOTOR_SPEED);
  analogWrite(MOTOR1_B_PIN, 0);
  
  analogWrite(MOTOR2_A_PIN, MAX_MOTOR_SPEED);
  analogWrite(MOTOR2_B_PIN, 0);
}

void rotateRight()
{
  stopMotors();
  
  analogWrite(MOTOR1_A_PIN, 0);
  analogWrite(MOTOR1_B_PIN, MAX_MOTOR_SPEED);
  
  analogWrite(MOTOR2_A_PIN, 0);
  analogWrite(MOTOR2_B_PIN, MAX_MOTOR_SPEED);
}

void turnLeftForward()
{
  stopMotors();
  
  analogWrite(MOTOR1_A_PIN, 0);
  analogWrite(MOTOR1_B_PIN, MAX_MOTOR_SPEED);
  
  analogWrite(MOTOR2_A_PIN, 0);
  analogWrite(MOTOR2_B_PIN, 0);
}

void turnRightForward()
{
  stopMotors();
  
  analogWrite(MOTOR1_A_PIN, 0);
  analogWrite(MOTOR1_B_PIN, 0);
  
  analogWrite(MOTOR2_A_PIN, MAX_MOTOR_SPEED);
  analogWrite(MOTOR2_B_PIN, 0);
  
}

void turnLeftBackward()
{
  stopMotors();
  
  analogWrite(MOTOR1_A_PIN, MAX_MOTOR_SPEED);
  analogWrite(MOTOR1_B_PIN, 0);
  
  analogWrite(MOTOR2_A_PIN, 0);
  analogWrite(MOTOR2_B_PIN, 0);
}

void turnRightBackward()
{
  stopMotors();
  
  analogWrite(MOTOR1_A_PIN, 0);
  analogWrite(MOTOR1_B_PIN, 0);
  
  analogWrite(MOTOR2_A_PIN, 0);
  analogWrite(MOTOR2_B_PIN, MAX_MOTOR_SPEED);
}
