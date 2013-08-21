#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     FourBar,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
#pragma config(Sensor, S3,     HTGYRO,         sensorAnalogInactive)

#include "drivers/hitechnic-gyro.h"

float rotSpeed;
float heading;

void StartGyro()
{
	rotSpeed = 0;
  heading = 0;
  HTGYROstartCal(HTGYRO);
  time1[T1] = 0;
}
void UpdateGyro()
{
    while (time1[T1] < 20)
    {
      wait1Msec(1);
    }
    time1[T1]=0;
    rotSpeed = HTGYROreadRot(HTGYRO);
    heading += rotSpeed * 0.02;
    nxtDisplayCenteredBigTextLine(3, "%2.2f", heading);
}

float ReturnGyroDegrees()
{
		return heading;
}

void ZeroGyro()
{
	heading = 0;
}
void TurnDegree(int Degree, int DSpeed, int ESpeed)
{
	ZeroGyro();
	while(ReturnGyroDegrees() < Degree - 2 || ReturnGyroDegrees() > Degree + 2)
	{
		motor[motorD] = -DSpeed;
		motor[motorE] = ESpeed;
	}
}
void Move(int Power, int Rotations)
{
	nMotorEncoder[motorD] = 0;
	while(abs(nMotorEncoder[motorD]) <= Rotations * 1440)
	{
		motor[motorD] = -Power;
		motor[motorE] = Power;
	}
	motor[motorD] = 0;
	motor[motorE] = 0;
}

void Turn(int DPower, int EPower, int Time)
{
	motor[motorD] = -DPower;
	motor[motorE] = EPower;
	Sleep(Time);
	motor[motorD] = 0;
	motor[motorE] = 0;
}


task SensorUpdate()
{
	while(true)
	{
		UpdateGyro();
	}
}
void Initialize()
{
	StartGyro();
	StartTask(SensorUpdate);
}

//Methods:
//Move(Power, WheelRotations);
//TurnDegree(Degree, ESpeed, DSpeed);
task main()
{
	Move(50, 2);
	TurnDegree(90, 25, -25);
}
