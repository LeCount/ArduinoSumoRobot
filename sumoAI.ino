#include "sumo_AI.h"

void setup() 
{
  Serial.begin(9600);
  configure_motors();
}

void loop() 
{
  start_sumo();
}
