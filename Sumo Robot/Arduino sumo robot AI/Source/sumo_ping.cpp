#include "sumo_ping.h"

int ping()
{
  unsigned long pulseduration;
  
  //send sound wave
  pinMode(PING_PIN, OUTPUT);
  digitalWrite(PING_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_PIN, HIGH);
  delayMicroseconds(7);
  digitalWrite(PING_PIN, LOW);
  
  //wait for sound to bounce back
  pinMode(PING_PIN, INPUT);
  pulseduration =  pulseIn(PING_PIN, HIGH);
  
  return roundOfDistance(convertMicrosecToCm(pulseduration/2));
}

long convertMicrosecToCm(long microseconds)
{
  return microseconds/MICROSECONDS_PER_CM;
}

int roundOfDistance(long cm)
{
  return (int) cm;
}
