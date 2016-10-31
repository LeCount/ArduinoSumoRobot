#ifndef SUMO_SERVO_H
#define SUMO_SERVO_H

/*Assuming the usage of a SG9 g9 Micro Servo.*/
/*Info: https://www.arduino.cc/en/Tutorial/Ping 
        http://www.micropik.com/PDF/SG90Servo.pdf
*/

#include <Arduino.h>
#include "sumo_config.h"
#include <Servo.h>

/*Global servo variables. Variables are only declared here!*/
extern int servo_pos;
extern Servo servo;

/*Returns the current position of the servo.*/
int  getServoPos();

/*Set the position of the servo in degrees.*/
void setServoPos(int new_pos);

/*Sweep servo right and left once, within the specified maximum servo angle.*/
void sweepServo();

#endif
