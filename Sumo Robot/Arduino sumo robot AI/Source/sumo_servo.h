#ifndef SUMO_SERVO_H
#define SUMO_SERVO_H

/*Assuming the usage of a SG9 g9 Micro Servo.*/
/*Info: https://www.arduino.cc/en/Tutorial/Ping 
        http://www.micropik.com/PDF/SG90Servo.pdf
*/

/*Power consumption: 550 mA.*/

#include <Arduino.h>
#include "sumo_config.h"
#include <Servo.h>

extern Servo servo;

void configureServo();

/*Returns the current position of the servo.*/
int  getServoPos();

/*Set the position of the servo in degrees.*/
void setServoPos(int new_pos);

/*Move the servo, in the current direction, one tick (specified in config.h).*/
void tickServo();

#endif
