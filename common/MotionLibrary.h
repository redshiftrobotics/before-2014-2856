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
