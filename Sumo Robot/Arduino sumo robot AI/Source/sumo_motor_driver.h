#ifndef SUMO_MOTOR_DRIVER_H
#define SUMO_MOTOR_DRIVER_H

/*Assuming the usage of a L9110S-based 2-Channel motor driver module.*/
/*Info: http://me.web2.ncut.edu.tw/ezfiles/39/1039/img/617/L9110_2_CHANNEL_MOTOR_DRIVER.pdf */

/*On-board 2 L9110 motor control chip
 * -Module can be driven by two dc motors at the same time or one phase 4 line 2
 *  type stepping motor
 * -Input voltage: 2.5-12V DC
 * -Each channel has a continuous output current 800 ma
 * -PCB Size: 29.2mm x 23mm
 * 
 *Pin Configuration
 * B-IA: Motor B Input A
 * B-IB: Motor B Input B
 * GND: ground
 * VCC: 2.5V-12V DC
 * A-IA: Motor A Input A
 * A-IB: Motor B Input B
*/

/*Power consumption per motor: (MIN 120 mA) (MAX 1600mA STALL) */

#include <Arduino.h>
#include "sumo_config.h"

/*Set the pin-configuration for the motor controller.*/
void configureMotors();

void stopMotors();

void moveForward();

void moveBackward();

void rotateLeft();

void rotateRight();

void turnLeftForward();

void turnRightForward();

void turnLeftBackward();

void turnRightBackward();

#endif
