/*
libarm
*/

#include "LimitswitchLibrary.h"

bool ArmLibrary_FourBarTrackingFailure = false;

void MoveArm(float Rotations, float Power)
{
	if (!bottomLimitSwitchTouched()) {

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

	} else {
		if (bottomLimitSwitchTouched()) {
			motor[FourBar] = 100;
		} else if (topLimitSwitchTouched()) {
			motor[FourBar] = -100;
		}
		while (bottomLimitSwitchTouched() || topLimitSwitchTouched()) {
			Sleep(10);
		}
	}
}

void MoveVCupToPosition(int Position)
{
	//FIXME
	servo[servo1] = 255 - Position;
	servo[servo2] = Position;
}

void MoveVCupToAngle() {
	//FIXME
	MoveVCupToPosition(175);
}

void MoveVCupToUpright() {
	//FIXME
	MoveVCupToPosition(0);
}

/*
PURPOSE:
move the 4-bar up to certain positions.

ARGUMENTS:
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
			MoveVCupToUpright();
		case 1:
			//if the arm is level with the bottom peg
			MoveArm(1, power);
		case 1.9:
			//if the arm is just below the middle peg
			MoveArm(0.1, power);
			MoveVCupToUpright();
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
PURPOSE:
move the 4-bar down to certain positions.

ARGUMENTS:
power is just plain servo power.

position is a one of the following values:
1, 1.9, 2
1 is the bottom bar, 2 is the middle bar. x.9 is just below x, for after we put the ring on.
0.9 is illegal because it would break the servo.

OPTIONAL ARGUMENTS:
moveVCup determines whether the V-Cup automatically moves for scoring and dispensing operations.
this option defaults to true. be careful when passing false, as this method and all other methods
*do not compensate* for the absense of VCup movement. it is your responsibility to keep track of
where the VCup is and make sure that nothing bad happens.
tl;dr: everything assumes that this option is true. it's your responsibility to make sure that other
components don't screw up because the VCup isn't where they expect it to be.
*/
float MoveArmDown(float position, float power, bool moveVCup = true)
{
	if (!ArmLibrary_FourBarTrackingFailure) {
		//FIXME
		//needs to be calibrated with proper rotation values
		switch(position) {
			case 0.9:
				//if the arm is just below the bottom peg
				//do nothing, this would break the servo and thus is illegal
			case 1:
				//if the arm is level with the bottom peg
				MoveArm(-0.1, power);
				MoveVCupToAngle();
			case 1.9:
				//if the arm is just below the middle peg
				MoveArm(-0.9, power);
			case 2:
				//if the arm is level with the middle peg
				MoveArm(-0.1, power);
				MoveVCupToAngle();
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
	} else {
		MoveArm(0.1, power);
	}
	return position;
}
