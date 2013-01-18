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

/*
move the 4-bar up to certain positions.
power is just plain servo power.
position is a one of the following values:
0.9, 1, 1.9
1 is the bottom bar, 2 is the middle bar. x.9 is just below x, for after we put the ring on.
2 is illegal because it would break the servo.
*/
float MoveArmUp(float position, float power)
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
			//do nothing, this would break the servo and thus is illegal
		default:
	}

	//figure out where the position is now and return it
	switch (position) {
				case 0.9:
					position = 1;
					break;
				case 1:
					position = 2;
					break;
				case 1.9:
					position = 2;
					break;
				case 2:
					position = 2;
					break;
				default:
		}
		return position;
}

/*
move the 4-bar down to certain positions.
power is just plain servo power.
position is a one of the following values:
1, 1.9, 2
1 is the bottom bar, 2 is the middle bar. x.9 is just below x, for after we put the ring on.
0.9 is illegal because it would break the servo
*/
float MoveArmDown(float position, float power)
{
	//FIXME
	//needs to be calibrated with proper rotation values
	switch(position) {
		case 0.9:
			//if the arm is just below the bottom peg
			//do nothing, this would break the servo and thus is illegal
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

	//figure out where the position is now and return it
	switch (position) {
				case 2:
					position = 1.9;
					break;
				case 1.9:
					position = 1;
					break;
				case 1:
					position = 0.9;
					break;
				case 0.9:
					position = 0.9;
					break;
				default:
	}
	return position;
}
