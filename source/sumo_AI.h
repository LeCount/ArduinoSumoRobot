#ifndef SUMO_AI_H
#define SUMO_AI_H

#include "sumo_servo.h"
#include "sumo_ping.h"
#include "sumo_qtr_sensors.h"
#include "sumo_motor_driver.h"

/*This is the main loop for the sumo robot AI.*/
void start();

/*Test the ping-sensor. The distance measured is displayed on the Serial Monitor.*/
void testPing();

/*Test the servo. The result is displayed on the Serial Monitor.*/
void testServo();

/*Test the QTR-sensors. The result is displayed on the Serial Monitor.*/
void testQTRSensors();

/*Test the motors.*/
void testMotors();

/*Read sensors.*/
void sense();

/*Interpret sensor readings.*/
void plan();

/*Perform action based on how the sensor-data was interpreted.*/
void act();

#endif
