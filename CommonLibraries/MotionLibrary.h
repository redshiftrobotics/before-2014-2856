void Move(int Power, float Rotations)
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

void Turn(int DPower, float EPower, int Time)
{
	motor[motorD] = -DPower;
	motor[motorE] = EPower;
	Sleep(Time);
	motor[motorD] = 0;
	motor[motorE] = 0;
}
