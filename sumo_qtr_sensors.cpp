#include "sumo_qtr_sensors.h"

/*Global QTR-reflectance-sensor variables. Variable are defined here. */
int sensor_values[NUM_OF_QTR_SENSORS];
bool sensor_detection[NUM_OF_QTR_SENSORS];

int getSenario();

QTRSensorsAnalog qtr_sensors(
  (unsigned char[]) {QTR_FRONT_LEFT_PIN, QTR_FRONT_RIGHT_PIN, QTR_BACK_LEFT_PIN, QTR_BACK_RIGHT_PIN}, 
  NUM_OF_QTR_SENSORS, 
  QTR_TIMEOUT_MICROSEC, 
  QTR_EMITTER_PIN); 

int readQTRSensors()
{
  int senario = NO_LINE;
  int sensor_index = 0;
  
  qtr_sensors.read(sensor_values);

  for(sensor_index = 0; sensor_index < NUM_OF_QTR_SENSORS; sensor_index += 1)
  {
    if(sensor_index == 0)
      Serial.print("FL: ");
    else if(sensor_index == 1)
      Serial.print("FR: "); 
    else if(sensor_index == 2)
      Serial.print("BL: ");
    else 
      Serial.print("BR: ");
      
    Serial.println(sensor_values[sensor_index]);
    
    if(sensor_values[sensor_index] > 0 && sensor_values[sensor_index] <= QTR_COLOR_LIMIT_VAL)
    {
      sensor_detection[sensor_index] = true;
    }
    else
    {
      sensor_detection[sensor_index] = false;
    }
  }
  senario = getSenario();
  return senario;
}

int getSenario()
{
  if(sensor_detection[LINE_F_LEFT] && sensor_detection[LINE_F_RIGHT])
  {
    return LINE_FRONT;
  }
  else if(sensor_detection[LINE_F_LEFT])
  {
    return LINE_F_LEFT;
  }
  else if(sensor_detection[LINE_F_RIGHT])
  {
    return LINE_F_RIGHT;
  }
  else if(sensor_detection[LINE_B_LEFT]&& sensor_detection[LINE_B_RIGHT])
  {
    return LINE_BACK;
  }
  else if(sensor_detection[LINE_B_LEFT])
  {
    return LINE_B_LEFT;
  }
  else if(sensor_detection[LINE_B_RIGHT])
  {
    return LINE_B_RIGHT;
  }
  else
  {
    return NO_LINE;
  }
}

