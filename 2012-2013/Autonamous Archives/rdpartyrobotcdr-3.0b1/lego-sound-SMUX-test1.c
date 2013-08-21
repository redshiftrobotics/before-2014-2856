#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     FourBar,       tmotorTetrix, openLoop)
#pragma config(Sensor, S2,     HTSMUX,              sensorI2CCustom)
#include "drivers/hitechnic-sensormux.h"
#include "drivers/lego-sound.h"


const tMUXSensor LEGOSND = msensor_S1_1;
int soundnorm;
int ToggleDirection = 0;
task main ()
{
	while(true)
	{
		//nxtDisplayString(1, "%i", soundnorm);
  	soundnorm = SNDreadNorm(LEGOSND);
  	if (soundnorm < 55)
  	{

  		if (ToggleDirection == 1)
  		{
  			ToggleDirection = 2;
  		}
			else if (ToggleDirection == 0)
			{
				ToggleDirection = 1;
			}
			else if (ToggleDirection == 2)
  		{
  			ToggleDirection = 0;
  		}
			Sleep(200);
  	}
  	if (ToggleDirection == 0)
  	{
  			eraseDisplay();
  			nxtDisplayCenteredBigTextLine(1, "Left");
  			motor[motorD] = 50;
  			motor[motorE] = 30;
  	}
		if (ToggleDirection == 2)
		{
			eraseDisplay();
			nxtDisplayCenteredBigTextLine(1, "Right");
			motor[motorD] = 30;
			motor[motorE] = 50;
		}
		if (ToggleDirection == 1)
		{
			eraseDisplay();
			nxtDisplayCenteredBigTextLine(1, "Straight");
			motor[motorD] = 40;
			motor[motorE] = 40;
		}
	}
}
