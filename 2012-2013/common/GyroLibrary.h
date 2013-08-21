#include "hitechnic-gyro.h"

float rotSpeed;
float heading;

void StartGyro()
{
	float rotSpeed = 0;
  float heading = 0;
  HTGYROstartCal(HTGYRO);
  time1[T1] = 0;
}
void UpdateGyro()
{
    while (time1[T1] < 20)
    {
      wait1Msec(1);
    }
    time1[T1]=0;
    rotSpeed = HTGYROreadRot(HTGYRO);
    heading += rotSpeed * 0.02;
    nxtDisplayCenteredBigTextLine(3, "%2.2f", heading);
}

float ReturnGyroDegrees()
{
		return heading;
}

void ZeroGyro()
{
	heading = 0;
}
