#include "GyroLibrary.h"

void TurnDegree(int Degree, int DSpeed, int ESpeed)
{
	ZeroGyro();
	while(ReturnGyroDegrees() < Degree - 2 || ReturnGyroDegrees() > Degree + 2)
	{
		motor[motorD] = -DSpeed;
		motor[motorE] = ESpeed;
	}
}
