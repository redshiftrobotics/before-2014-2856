#include "drivers/hitechnic-gyro.h"

float TempRot = 0;
float TimeTaken;
float TotalRot = 0;
float Time;

void UpdateGyro()
{
		Time = time1[T1];
		TimeTaken = Time / 1000;
		TotalRot += TempRot * TimeTaken;

		time1[T1] = 0;
		TempRot = HTGYROreadRot(HTGYRO);
		wait1Msec(0);

}

float ReturnGyroDegrees()
{
		return TotalRot;
}
void ZeroGyro()
{
	TotalRot = 0;
}
