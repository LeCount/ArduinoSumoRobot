#include "sumo_qtr_sensors.h"

int sensor_values[NUM_OF_QTR_SENSORS];
bool sensor_detection[NUM_OF_QTR_SENSORS];

QTRSensorsAnalog qtr_sensorsFront(
  (unsigned char[]) {QTR_FRONT_LEFT_PIN, QTR_FRONT_RIGHT_PIN},
  NUM_OF_QTR_SENSORS, 
  QTR_TIMEOUT_MICROSEC, 
  QTR_EMITTER_PIN); 

  QTRSensorsAnalog qtr_sensorsBack(
  (unsigned char[]) {QTR_BACK_LEFT_PIN, QTR_BACK_RIGHT_PIN},
  NUM_OF_QTR_SENSORS, 
  QTR_TIMEOUT_MICROSEC, 
  QTR_EMITTER_PIN); 

int readQTRSensorsFront()
{
  int sensor_index = 0;
  
  qtr_sensorsFront.read(sensor_values);
    
  if(sensor_values[0] > 0 && sensor_values[0] <= QTR_COLOR_LIMIT_VAL)
  {
    sensor_detection[0] = false;
  }
  else
  {
    sensor_detection[0] = true;
  }

  if(sensor_values[1] > 0 && sensor_values[1] <= QTR_COLOR_LIMIT_VAL)
  {
    sensor_detection[1] = false;
  }
  else
  {
    sensor_detection[1] = true;
  }

  return getSenarioFront();
}

int getSenarioFront()
{
  if(sensor_detection[0] || sensor_detection[1])
  {
    return LINE_FRONT;
  }
  else
  {
    return NO_LINE;
  }
}

int readQTRSensorsBack()
{
  int sensor_index = 0;
  
  qtr_sensorsBack.read(sensor_values);
  
  if(sensor_values[0] > 0 && sensor_values[0] <= QTR_COLOR_LIMIT_VAL)
  {
    sensor_detection[0] = false;
  }
  else
  {
    sensor_detection[0] = true;
  }

  if(sensor_values[1] > 0 && sensor_values[1] <= QTR_COLOR_LIMIT_VAL)
  {
    sensor_detection[1] = false;
  }
  else
  {
    sensor_detection[1] = true;
  }

  return getSenarioBack();
}

int getSenarioBack()
{
  if(sensor_detection[0] || sensor_detection[1])
  {
    return LINE_BACK;
  }
  else
  {
    return NO_LINE;
  }
}

String getQTRResultAsText(int result)
{
  switch(result)
  {
  case -1: return "NO_LINE";
  case 0: return "LINE_F_LEFT";
  case 1: return "LINE_F_RIGHT"; 
  case 2: return "LINE_B_LEFT";
  case 3: return "LINE_B_RIGHT";
  case 4: return "LINE_FRONT";
  case 5: return "LINE_BACK";
  default: return "NO_LINE";
  }
}
