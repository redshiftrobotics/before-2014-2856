#include "GyroLibrary.h"

void RotateAmount(int Degrees)
{
	ZeroGyro();

	while (ReturnGyroDegrees() < Degrees - 2 || ReturnGyroDegrees() > Degrees + 2)
	{
		motor[motorD] = -30;
		motor[motorE] = -30;
	}
}
