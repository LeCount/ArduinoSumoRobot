#ifndef SUMO_CONFIG_H
#define SUMO_CONFIG_H

//************************************
//**     Configure PING-sensor      **
//************************************

#define PING_PIN                      7       //Signal-pin to be used for sensor
#define MAX_VALID_PING_DISTANCE_CM    25      //Maximum distance to measure
#define MIN_VALID_PING_DISTANCE_CM    0       //Minimum distance to measure
#define MICROSECONDS_PER_CM           29      //Check datasheet

//************************************
//**     POLOLU QTR-1A sensors      **
//************************************

#define LED_PIN                       6       //Signal-pin to be used for LED

//************************************
//**     POLOLU QTR-1A sensors      **
//************************************

#define QTR_COLOR_LIMIT_VAL           100     //Number indicating the breakingpoint between dark and light colors

#define QTR_FRONT_LEFT_PIN            2       //Signal-pin to be used for sensor
#define QTR_FRONT_RIGHT_PIN           3       //Signal-pin to be used for sensor
#define QTR_BACK_LEFT_PIN             1       //Signal-pin to be used for sensor
#define QTR_BACK_RIGHT_PIN            0       //Signal-pin to be used for sensor

#define NUM_OF_QTR_SENSORS            2       // Number of sensors to be used
#define QTR_TIMEOUT_MICROSEC          10      // waits for 10 us for qtr-sensor outputs to go low
#define QTR_EMITTER_PIN               -1      // emitter is controlled by digital pin 6 (optional)

//************************************
//**        Servo G90 9g            **
//************************************

#define SERVO_PIN                     8       //Signal-pin to be used for servo
#define SERVO_STEP_ANGLE              45      //Step-change in angle, when sweeping servo
#define SERVO_MIN_ANGLE               0       //Minimum servo angle in degrees
#define SERVO_MID_ANGLE               90      //Mid servo angle in degrees
#define SERVO_FRONT_OFFSET_ANGLE      40      //Mid servo angle in degrees
#define SERVO_MAX_ANGLE               180     //Maximum servo angle in degrees
#define SERVO_PRACTICAL_MAX_ANGLE     180     //Maximum servo angle in degrees
#define SERVO_DELAY                   300     //Maximum servo angle in degrees

//************************************
//**       Motor Driver L9110       **
//************************************

#define MAX_MOTOR_SPEED               255     //Maximum motor speed (PWM)
#define MOTOR1_A_PIN                  9       //Signal-pin to be used for motor1, input A
#define MOTOR1_B_PIN                  10      //Signal-pin to be used for motor1, input B
#define MOTOR2_A_PIN                  11      //Signal-pin to be used for motor2, input A
#define MOTOR2_B_PIN                  12      //Signal-pin to be used for motor2, input B

#endif
