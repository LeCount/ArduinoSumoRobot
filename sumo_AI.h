#ifndef SUMO_AI_H
#define SUMO_AI_H

#include <QueueList.h>
#include "sumo_servo.h"
#include "sumo_ping.h"
#include "sumo_qtr_sensors.h"
#include "sumo_motor_driver.h"

#define FORWARD   1
#define BACKWARD  2
#define LEFT      3
#define RIGHT     4

/*A class for storing actions to be performed by the robot.*/
class SumoAction
{
  public:
    
    /*Variable for denoting what type of action this is.*/
    int type;

    /*Variable for denoting how many times this action should be repeated.*/
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

/*Settup-function for the sumo AI.*/
void setupAI();

/*Read all sensors and collect the states of each sensor.*/
void sense();

/*Tick servo and saves the servo position.*/
void sweepServo();

/*Read ping-sensor, and gather the resulting state.*/
void checkPing();

/*Read all qtr-line-sensor, and gather the resulting state.*/
void checkQTRS();

/*Interpret the collected sensor readings (states).*/
void plan();

/*Clears the action queue from all it's elements.*/
void clearAllActions();

/*Perform action based on how the sensor-data was interpreted.*/
void act();

/*Perform the next action, according to the type of the action, and the action iterator.*/
void performAction(int action_type, int action_iterator);



//*****************************************
//***     TEST FUNCTIONS (OPTIONAL)     ***
//*****************************************


/*Test the ping-sensor. The distance measured is displayed on the Serial Monitor.*/
void testPing();

/*Test the servo. The result is displayed on the Serial Monitor.*/
void testServo();

/*Test the QTR-sensors. The result is displayed on the Serial Monitor.*/
void testQTRSensors();

/*Test the motors, and make sure they are configured correctly. 
 *Use the monitor to compare your actual motor movement.*/
void testMotors();

#endif
