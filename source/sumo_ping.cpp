#include "sumo_ping.h"

void sendSoundWave();
long waitForBounce();

int ping()
{
  long duration_in_microsec = 0;

  sendSoundWave();
  duration_in_microsec = waitForBounce();
  return roundOfDistance(convertMicrosecToCm(duration_in_microsec));
}

long convertMicrosecToCm(long microseconds)
{
  return microseconds/MICROSECONDS_PER_CM/2;
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

