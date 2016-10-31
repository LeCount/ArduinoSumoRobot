#include "sumo_ping.h"

void sendSoundWave();
long waitForBounce();

int ping()
{
  int distance;
unsigned long pulseduration=0;

  // set pin as output so we can send a pulse
 pinMode(7, OUTPUT);
// set output to LOW
 digitalWrite(7, LOW);
 delayMicroseconds(5);
 
 // now send the 5uS pulse out to activate Ping)))
 digitalWrite(7, HIGH);
 delayMicroseconds(5);
 digitalWrite(7, LOW);
 
 // now we need to change the digital pin
 // to input to read the incoming pulse
 pinMode(7, INPUT);
 
 // finally, measure the length of the incoming pulse
 pulseduration=pulseIn(7, HIGH);

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

void sendSoundWave()
{
  pinMode(PING_PIN, OUTPUT);
  digitalWrite(PING_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING_PIN, LOW);
}

long waitForBounce()
{
  pinMode(PING_PIN, INPUT);
  return pulseIn(PING_PIN, HIGH);
}

