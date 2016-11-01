#include "sumo_ping.h"

int ping()
{
  int distance;
  unsigned long pulseduration = 0;
  
  sendSoundWave();
  pulseduration = waitForBounce();
  
  return roundOfDistance(convertMicrosecToCm(pulseduration/2));
}

void sendSoundWave()
{
  // set pin as output so we can send a pulse
  pinMode(7, OUTPUT);
  
  // set output to LOW
  digitalWrite(7, LOW);
  delay(50);
   
  // now send the 5uS pulse out to activate Ping)))
  digitalWrite(7, HIGH);
  delayMicroseconds(5);
  digitalWrite(7, LOW);
}

unsigned long waitForBounce()
{
  // now we need to change the digital pin
  // to input to read the incoming pulse
  pinMode(7, INPUT);
   
  // finally, measure the length of the incoming pulse
  return pulseIn(7, HIGH);
}

long convertMicrosecToCm(long microseconds){return microseconds/MICROSECONDS_PER_CM;}

int roundOfDistance(long cm){return (int) cm;}

