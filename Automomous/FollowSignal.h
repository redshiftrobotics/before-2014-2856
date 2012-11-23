#ifndef __FOLLOW_SIGNAL_H__
#define __FOLLOW_SIGNAL_H__

#include "GetDegrees.h"

void FollowSignal()
{
	int Power = 20;
	int Turn = 10;
	int Degree;
	int CheckTimes = 0;
	while(CheckTimes <= 9)
	{
		motor[motorD] = 0;
		motor[motorE] = 0;
		Degree = GetDegrees();

		if (Degree > 0)
		{
			eraseDisplay();
			nxtDisplayString(6, "Right");
			motor[motorD] = -(Power + abs(Degree * 4) + Turn);
			motor[motorE] = (Power);
		}
		else if(Degree < 0)
		{
			eraseDisplay();
			nxtDisplayString(6, "Left");
			motor[motorD] = -(Power + Turn);
			motor[motorE] = (Power + abs(Degree * 4));
		}
		else
		{
			eraseDisplay();
			nxtDisplayString(6, "Straight");
			motor[motorD] = -(Power + Turn);
			motor[motorE] = (Power);
		}
			Sleep(500);
		CheckTimes++;

		if (CheckTimes == 5)
		{
			MoveVCupToPosition(200);
		}
		if (CheckTimes == 9)
		{
			MoveVCupToPosition(400);
		}
	}

	motor[motorD] = 0;
	motor[motorE] = 0;

}

#endif // ifndef __FOLLOW_SIGNAL_H__
