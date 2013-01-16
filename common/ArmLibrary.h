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

void MoveArmUp(float position, float power)
{
	//FIXME
	//needs to be calibrated with proper rotation values
	switch(position) {
		case 0.9:
			//if the arm is just below the bottom peg
			MoveArm(0.1, power);
		case 1:
			//if the arm is level with the bottom peg
			MoveArm(1, power);
		case 1.9:
			//if the arm is just below the middle peg
			MoveArm(0.1, power);
		case 2:
			//if the arm is level with the middle peg
		default:
	}
}

void MoveArmDown(float position, float power)
{
	//FIXME
	//needs to be calibrated with proper rotation values
	switch(position) {
		case 0.9:
			//if the arm is just below the bottom peg
		case 1:
			//if the arm is level with the bottom peg
			MoveArm(-0.1, power);
		case 1.9:
			//if the arm is just below the middle peg
			MoveArm(-0.9, power);
		case 2:
			//if the arm is level with the middle peg
			MoveArm(-0.1, power);
		default:
	}
}
