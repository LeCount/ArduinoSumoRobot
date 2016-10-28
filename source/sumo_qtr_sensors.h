#ifndef SUMO_QTR_SENSORS_H
#define SUMO_QTR_SENSORS_H

#include <Arduino.h>
#include "sumo_config.h"
#include <QTRSensors.h>

/*Assuming the usage of Pololu QTR-1A Reflectance sensors. https://www.pololu.com/product/958 */
/*Info: https://www.pololu.com/docs/0J19 */

/*
 * Specifications:

* Dimensions: 0.3" x 0.5" x 0.1" (without optional header pins installed)
* Operating voltage: 5.0 V
* Supply current: 17 mA
* Output format: analog voltage
* Output voltage range: 0  to supplied voltage
* Optimal sensing distance: 0.125" (3 mm)
* Maximum recommended sensing distance: 0.25" (6 mm)
* Weight without header pins: 0.008 oz (0.2 g)
*/

/*Global QTR-reflectance-sensor variables. Variables are only declared here!*/
extern QTRSensorsAnalog qtr_sensors; 
extern int sensor_values[];
extern bool sensor_detection[];

#define LINE_INVALID -1
#define LINE_F_LEFT   0
#define LINE_F_RIGHT  1
#define LINE_B_LEFT   2
#define LINE_B_RIGHT  3
#define LINE_FRONT    4
#define LINE_BACK     5

/*Depending on the current situation, this function returns 
 *an int, corresponding to one of the defined values above.*/
int readQTRSensors();

#endif
