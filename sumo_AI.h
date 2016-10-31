#ifndef SUMO_AI_H
#define SUMO_AI_H

//#include <QueueList.h>
#include "sumo_servo.h"
#include "sumo_ping.h"
#include "sumo_qtr_sensors.h"
#include "sumo_motor_driver.h"

class SumoAction
{
  public:
    int type;
    int iterations;

    SumoAction()
    {
      type = 0;
      iterations = 0;
    }

    SumoAction(int t, int i)
    {
      type = t;
      iterations = i;
    }
};

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
