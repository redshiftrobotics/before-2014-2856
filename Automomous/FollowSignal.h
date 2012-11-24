#ifndef __FOLLOW_SIGNAL_H__
#define __FOLLOW_SIGNAL_H__

#include "GetDegrees.h"
#include "IronWood.h"


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
			MoveConstantSpeedMotorD(Power + abs(Degree * 4), 500);
			MoveConstantSpeedMotorE(Power, 500);

			//motor[motorD] = -(Power + abs(Degree * 4) + Turn);
			//motor[motorE] = (Power);
		}
		else if(Degree < 0)
		{
			eraseDisplay();
			nxtDisplayString(6, "Left");

			MoveConstantSpeedMotorD(Power, 500);
			MoveConstantSpeedMotorE(Power + abs(Degree * 4), 500);

			//motor[motorD] = -(Power + Turn);
			//motor[motorE] = (Power + abs(Degree * 4));
		}
		else
		{
			eraseDisplay();
			nxtDisplayString(6, "Straight");

			MoveConstantSpeedMotorD(Power, 500);
			MoveConstantSpeedMotorE(Power, 500);

			//motor[motorD] = -(Power + Turn);
			//motor[motorE] = (Power);
		}
		//Sleep(500);
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
