#include "drivers/hitechnic-gyro.h"

float rotSpeed;
float heading;
task UpdateGyro;

task UpdateGyro()
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

void StartGyro()
{
	float rotSpeed = 0;
  float heading = 0;
  HTGYROstartCal(HTGYRO);
  time1[T1] = 0;
  StartTask(UpdateGyro);
}

float GyroDegrees()
{
		return heading;
}

void ResetGyro()
{
	heading = 0;
}
