#ifndef __GET_DEGREES_H__
#define __GET_DEGREES_H__

#include "MoveServoToPosition.h"

int GetDegrees()
{
	int ServoDegree = 75;
	while(ServoDegree >= -75)
	{
		nxtDisplayString(3, "%i", ServoDegree);
		nxtDisplayString(4, "%i", S1RawValues[2]);
		MoveServoToPosition(ServoDegree);
		Sleep(50);
		ServoDegree = ServoDegree - 5;
		HTIRS2readAllACStrength(IRS1, S1RawValues[0], S1RawValues[1], S1RawValues[2], S1RawValues[3], S1RawValues[4]);
		if (S1RawValues[2] > BiggestServoValue)
		{
			NumberOfRepeats = 1;
			BiggestServoValue = S1RawValues[2];
			BiggestServoDegree = ServoDegree;
		}
		else if(S1RawValues[2] == BiggestServoValue)
		{
			NumberOfRepeats++;
		}
	}
	ServoDegree = 65;

	if (NumberOfRepeats == 1)
	{
		return BiggestServoDegree;
	}
	else if(NumberOfRepeats > 1)
	{
		return (BiggestServoDegree - NumberOfRepeats / 2 * 5);
	}
	return 0;
}

#endif // ifndef __GET_DEGREES_H__
