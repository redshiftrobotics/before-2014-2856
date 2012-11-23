#ifndef __MOVE_ARM_TO_MIDDLE_PEG_H__
#define __MOVE_ARM_TO_MIDDLE_PEG_H__

#include "Readlimitswitches.h"
#include "Limitcheck.h"

void MoveArmToMiddlePeg()
{
	while(readlimitswitches() != 1)
	{
		motor[FourBar] = -25;
	}
	Limitcheck();
	Sleep(500);
	motor[FourBar] = 0;
}

#endif // ifndef __MOVE_ARM_TO_MIDDLE_PEG_H__
