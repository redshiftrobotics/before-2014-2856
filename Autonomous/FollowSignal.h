#ifndef __FOLLOW_SIGNAL_H__
#define __FOLLOW_SIGNAL_H__

#include "GetDegrees.h"



void FollowSignal()
{
	int Power = 30;
	int Turn = 10;
	int Degree;
	int CheckTimes = 0;
	double Multiplier = 1.5;
	while(CheckTimes <= 7)
	{
		motor[motorD] = 0;
		motor[motorE] = 0;
		Degree = GetDegrees();

		if (Degree > 0)
		{
			motor[motorD] = -(Power + abs(Degree * Multiplier) + Turn);
			motor[motorE] = (Power);
		}
		else if(Degree < 0)
		{
			motor[motorD] = -(Power + Turn);
			motor[motorE] = (Power + abs(Degree * Multiplier));
		}
		else
		{
			motor[motorD] = -(Power + Turn);
			motor[motorE] = (Power);
		}

		Sleep(650);
		CheckTimes++;
		//if (CheckTimes == 2)
		//{
		//	motor[motorD] = -(Power * 2);
		//	motor[motorE] = (Power * 2);
		//	Sleep(1000);
		//}
		if (CheckTimes == 4)
		{
			Multiplier = 2.5;
		}
		if (CheckTimes == 4)
		{
			MoveVCupToPosition(200);
		}
		if (CheckTimes == 6)
		{
			MoveVCupToPosition(300);
		}
		if (CheckTimes == 7)
		{
			MoveVCupToPosition(400);
		}
	}

	motor[motorD] = 0;
	motor[motorE] = 0;

}

#endif // ifndef __FOLLOW_SIGNAL_H__
