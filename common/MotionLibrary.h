void Move(int Power, int Rotations)
{
	nMotorEncoder[motorD] = 0;
	while(abs(nMotorEncoder[motorD]) <= Rotations * 1440)
	{
		motor[motorD] = Power;
		motor[motorE] = Power;
	}
	motor[motorD] = 0;
	motor[motorE] = 0;
}
