#ifndef SUMO_CONFIG_H
#define SUMO_CONFIG_H

//************************************
//**     Configure PING-sensor      **
//************************************

#define PING_PIN                      1       //Signal-pin to be used for sensor
#define MAX_VALID_PING_DISTANCE_CM    400     //Maximum distance to measure
#define MIN_VALID_PING_DISTANCE_CM    0       //Minimum distance to measure
#define MICROSECONDS_PER_CM           29      //Check datasheet

//************************************
//**     POLOLU QTR-1A sensors      **
//************************************

#define QTR_COLOR_LIMIT_VAL           1000    //Number indicating the breakingpoint between dark and light colors

#define QTR_FRONT_LEFT_PIN            2       //Signal-pin to be used for sensor
#define QTR_FRONT_RIGHT_PIN           3       //Signal-pin to be used for sensor
#define QTR_BACK_LEFT_PIN             4       //Signal-pin to be used for sensor
#define QTR_BACK_RIGHT_PIN            5       //Signal-pin to be used for sensor

#define NUM_OF_QTR_SENSORS            4       // Number of sensors to be used
#define QTR_TIMEOUT_MICROSEC          2000    // waits for 2000 us for qtr-sensor outputs to go low
#define QTR_EMITTER_PIN               -1      // emitter is controlled by digital pin 6 (optional)

//************************************
//**        Servo G90 9g            **
//************************************

#define SERVO_PIN                     7       //Signal-pin to be used for servo
#define SERVO_STEP_DEGREE             1       //Step-change in angle, when sweeping servo
#define SERVO_MIN_ANGLE               0       //Minimum servo angle in degrees
#define SERVO_MID_ANGLE               90      //Mid servo angle in degrees
#define SERVO_MAX_ANGLE               180     //Maximum servo angle in degrees

//************************************
//**       Motor Driver L9110       **
//************************************

#define MOTOR1_A_PIN                  8       //Signal-pin to be used for motor1, input A
#define MOTOR1_B_PIN                  9       //Signal-pin to be used for motor1, input B
#define MOTOR2_A_PIN                  10      //Signal-pin to be used for motor2, input A
#define MOTOR2_B_PIN                  11      //Signal-pin to be used for motor2, input B

#endif
