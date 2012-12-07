#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     LimitSwitches,  sensorI2CCustom9V)
#pragma config(Sensor, S3,     IRS1,           sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     FourBar,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Sensor, S4,     HTGYRO,              sensorAnalogInactive)

#include "SpiderThread/OpenOperation.h"
#include "SpiderThread/CloseOperation.h"
#include "GyroLibrary.h"


void Update()
{
	UpdateGyro();
}

void Thread(int TimeMiliseconds, string Operation)
{
	OpenOperation(Operation);
	for (int i = 0; i < TimeMiliseconds; i++)
	{
		Update();
	}
	CloseOperation(Operation);
}
void Rotate90()
{
	ZeroGyro();

	while(abs(ReturnGyroDegrees()) < 85 || abs(ReturnGyroDegrees()) > 95)
	{
		nxtDisplayString(1, "%f", ReturnGyroDegrees());
		UpdateGyro();
		motor[motorD] = 30;
		motor[motorD] = 30;
	}
}

task main()
{
	string Move = "Move";
	Thread(1000, Move);
	Rotate90();
}
