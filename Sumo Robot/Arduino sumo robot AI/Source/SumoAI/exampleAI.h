/*This is an example of an artificial intelligence for a sumo-robot.
 *This AI incorporates Opponent detection/following, Line-detection, Motor control, and indication using an LED.
 *This simple AI has been implemented in a state machine-based manor. The design and flow of the states can be viewed in the folder: 'Sumo Robot\Sumo AI\Simple AI Example Flowcharts\'.
 *
 *Use this example to construct YOUR OWN AI! 
 *You can allso use the functions in sumo_test.h to make sure you have configured your electronics properly.
 *
 *For reasons to simplify and quicken the programmers understanding of the code, interaction with each sub-component of the robot's
 *system, are split into separate libs.
 *
 *Check your settings in config.h! Pin configurations, constants, etc...
 *
 *
 *Note that you might need to install some libraries on first startup in order to make this projekt work! They can be located in the folder: 'Sumo Robot\Sumo AI\Arduino libraries'
 *
 *Author: Stefan Danielsson, Knightec, 2016.  */

#ifndef EXAMPLEAI_H
#define EXAMPLEAI_H
 
/*This lib. is used for timer overflow interrumpts, and it provides a simple API against the arduino nano timer 2.*/
#include <MsTimer2.h>

/*Each one of all these libraries, controls one separate sub-sustem of the robot. */
#include "sumo_servo.h"
#include "sumo_ping.h"
#include "sumo_qtr_sensors.h"
#include "sumo_motor_driver.h"
#include "sumo_LED.h"
#include "sumo_test.h"

/*States of the robot AI.*/
#define START_STATE         0
#define MOVE_F_STATE        1
#define TURN_STATE          3
#define AVOID_LINE_STATE    4

/*This is the main loop for the sumo robot AI.*/
void start_sumo();

/*Settup-function for the sumo AI.*/
void setupAI();

/*Performs a measurment, sets the ping-state, and returns it.*/
bool checkPing();

/*Performs a measurement, sets the qtr-state, and returns it. 
 *The parameter 'dir' determines if the measurement is performed on the sensors at the front or the back.*/
bool checkQTR(int dir);

/*A callback-function user as a timer overflow interrupt, to check the qtr-sensors at the front of the robot.*/
void qtrCallbackFront();

/*A callback-function user as a timer overflow interrupt, to check the qtr-sensors at the back of the robot.*/
void qtrCallbackBack();

/*A callback-function user as a timer overflow interrupt, to check the ping-sensors.*/
void pingCallback();

/*A callback-function user as a timer overflow interrupt, to blink the LED, and count down until start (3 sec from clicking the ON-btn).*/
void LEDCallback();

/*Rotate the servo 90 degrees back and forth once, and checks ping at each position.*/
void sweepServo();

#endif
