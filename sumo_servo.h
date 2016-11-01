#ifndef SUMO_SERVO_H
#define SUMO_SERVO_H

/*Assuming the usage of a SG9 g9 Micro Servo.*/
/*Info: https://www.arduino.cc/en/Tutorial/Ping 
        http://www.micropik.com/PDF/SG90Servo.pdf
*/

#include <Arduino.h>
#include "sumo_config.h"
#include <Servo.h>

/*Returns the current position of the servo.*/
int  getServoPos();

/*Set the position of the servo in degrees.*/
void setServoPos(int new_pos);

/*Sweep (tick/step) servo right or left once, within the specified maximum servo angle.*/
void tickServo();

#endif
