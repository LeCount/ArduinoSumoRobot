#ifndef SUMO_AI_H
#define SUMO_AI_H

#include <ThreadController.h>
#include <Thread.h>
#include "sumo_servo.h"
#include "sumo_ping.h"
#include "sumo_qtr_sensors.h"
#include "sumo_motor_driver.h"

extern int ping_distance_cm;
extern int ping_angle_degrees;
extern int line_situation;

/*This is the main loop for the sumo robot AI.*/
void start_sumo();

/*Start threads that (1): Sweeps the servo back and forth
 *                   (2): Reads the ping sensor
 *                   (3): Reads the QTR-sensors*/
void startSensorThreads();

/*Callback function for the Timer.*/
void timerCallback();

/*Interpret sensor readings.*/
void plan();

/*Perform action based on how the sensor-data was interpreted.*/
void act();

/*Test the ping-sensor. The distance measured is displayed on the Serial Monitor.*/
void testPing();

/*Test the servo. The result is displayed on the Serial Monitor.*/
void testServo();

/*Test the QTR-sensors. The result is displayed on the Serial Monitor.*/
void testQTRSensors();

/*Test the motors.*/
void testMotors();

#endif
