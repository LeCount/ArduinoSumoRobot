#ifndef SUMO_PING_H
#define SUMO_PING_H

/*Assuming the usage of a DIGITAL* ping-sensor.*/
/*Info: https://www.arduino.cc/en/Tutorial/Ping */

#include <Arduino.h>
#include "sumo_config.h"

/*Perform one PING-measurment, and return the distance to the object in whole cm's.*/
int ping();

/*Based on the speed of sound, converts the "there-and-back-again-duration" 
 *into a cm-based distance (long).*/
long convertMicrosecToCm(long microseconds);

/*Round of cm's to whole cm's (int).*/
int roundOfDistance(long cm);

#endif
