/*Use these functions to make sure you have configured your electronics properly.
 *Check your settings in config.h!*/
 
#ifndef SUMO_TEST_H
#define SUMO_TEST_H

#include "sumo_ping.h";
#include "sumo_servo.h"
#include "sumo_qtr_sensors.h"
#include "sumo_motor_driver.h"
#include "sumo_LED.h"

//*****************************************
//***     TEST FUNCTIONS (OPTIONAL)     ***
//*****************************************

/*Test the ping-sensor. The distance measured is 
 *displayed on the Serial Monitor, if configured correctly.*/
void testPing();

/*Test the servo. The result is displayed on the Serial Monitor.*/
void testServo();

/*Test the QTR-sensors. The result is displayed on the Serial Monitor.*/
void testQTRSensors();

/*Test the motors, and make sure they are configured correctly. 
 *Use the monitor to compare the expected motion, to your actual motor movement.*/
void testMotors();

/*Test the LED. Look and see if LED blinks.*/
void testLED();

#endif
