void MoveArm(float Rotations, float Power)
{
	nMotorEncoder[FourBar] = 0;

		if (Rotations > 0)
		{
			while(nMotorEncoder[FourBar] < Rotations * 1440)
			{
				motor[FourBar] = Power;
			}
		}
		else
		{
			while(nMotorEncoder[FourBar] > Rotations * 1440)
			{
				motor[FourBar] = -Power;
			}
		}
	motor[FourBar] = 0;
}

void MoveVCupToPosition(int Position)
{
	servo[servo1] = 255 - Position;
	servo[servo2] = Position;
}
