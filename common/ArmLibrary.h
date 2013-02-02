/*
libarm
*/

#include "LimitswitchLibrary.h"

void printDebug(int arg1, int arg2) {
	/*eraseDisplay();
	nxtDisplayString(0, "position: %i", fourbarposition);
	//nxtDisplayString(1, "vcup status: %i", vcupangled);
	nxtDisplayString(3, "bls: %i", bottomLimitSwitchTouched());
	nxtDisplayString(2, "tls: %i", topLimitSwitchTouched());
	if (status == "MoveArm ") {
		nxtDisplayString(4, "status: %s %f %f", status, arg1, arg2);
	} else {
		nxtDisplayString(4, "status: %s", status);
	}*/
}

bool ArmLibrary_FourBarTrackingFailure = false;
const float ArmLibrary_FullPegMovement = 1.0;
const float ArmLibrary_BelowPegMovement = 0.1;
const float ArmLibrary_BelowPegToRegularMovement = 0.9;

void MoveArm(float Rotations, int Power)
{
	status = "MoveArm ";
	//printDebug(Rotations, Power);
	//nxtDisplayString(6, "MoveArm");

	nMotorEncoder[FourBar] = 0;
int encoderDebug;
		if (Rotations > 0)
		{
			while(nMotorEncoder[FourBar] < Rotations * 1440 && !bottomLimitSwitchTouched() && !topLimitSwitchTouched())
			{
				motor[FourBar] = Power;
				encoderDebug = nMotorEncoder[FourBar];
				//nxtDisplayString(5, "encoder: %i", encoderDebug);
			}
		}
		else
		{

			while(nMotorEncoder[FourBar] > Rotations * 1440 && !bottomLimitSwitchTouched() && !topLimitSwitchTouched())
			{
				int nPower = Power;
				if (nPower > 0) {
					nPower = nPower*(-1);
			}
				motor[FourBar] = nPower;
				encoderDebug = nMotorEncoder[FourBar];
				//nxtDisplayString(5, "encoder: %i", encoderDebug);
			}
		}

	if (bottomLimitSwitchTouched()) {
		motor[FourBar] = 100;
	} else if (topLimitSwitchTouched()) {
		motor[FourBar] = -100;
	}

	while (bottomLimitSwitchTouched() || topLimitSwitchTouched()) {
		ArmLibrary_FourBarTrackingFailure = true;
		Sleep(10);
	}

	motor[FourBar] = 0;
	//nxtDisplayString(6, "");
}

void MoveVCupToPosition(int Position)
{
	#ifndef VCUP_SUPPORT_DISABLED
	servo[servo1] = Position;
	#endif
}

void MoveVCupToAngle() {
	status = "MoveVCupToAngle";
	printDebug(0,0);
	MoveVCupToPosition(200);
}

void MoveVCupToUpright() {
	status = "MoveVCupToUpright";
	printDebug(0,0);
	MoveVCupToPosition(68);
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
int MoveArmUp(int position, int power)
{
	status = "MoveArmUp";
	printDebug(0,0);
	//Sleep(1000);
	if (!topLimitSwitchTouched() && !ArmLibrary_FourBarTrackingFailure)
	{
		//FIXME
		//needs to be calibrated with proper rotation values
		switch(position) {
			case 1:
				//if the arm is just below the bottom peg
				MoveArm(ArmLibrary_BelowPegMovement, power);
				MoveVCupToUpright();
				break;
			case 2:
				//if the arm is level with the bottom peg
				MoveArm(ArmLibrary_FullPegMovement, power);
				break;
			case 3:
				//if the arm is just below the middle peg
				MoveArm(ArmLibrary_BelowPegMovement, power);
				MoveVCupToUpright();
				break;
			case 4:
				//if the arm is level with the middle peg
				//do nothing, this would break the servo and thus is illegal
			default:
		}

		//figure out where the position is now and return it
		switch (position) {
			case 1:
				position = 2;
				break;
			case 2:
				position = 4;
				break;
			case 3:
				position = 4;
				break;
			case 4:
				position = 4;
				break;
			default:
		}
	} else {
		ArmLibrary_FourBarTrackingFailure = true;
		MoveArm(0.1, power);
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
int MoveArmDown(int position, int power, bool moveVCup = true)
{
	if (!bottomLimitSwitchTouched() && !ArmLibrary_FourBarTrackingFailure) {
		//FIXME
		//needs to be calibrated with proper rotation values
		switch(position) {
			case 1:
				//if the arm is just below the bottom peg
				//do nothing, this would break the servo and thus is illegal
				break;
			case 2:
				//if the arm is level with the bottom peg
				MoveArm(-ArmLibrary_BelowPegMovement, power);
				MoveVCupToAngle();
				break;
			case 3:
				//if the arm is just below the middle peg
				MoveArm(-ArmLibrary_BelowPegToRegularMovement, power);
				break;
			case 4:
				//if the arm is level with the middle peg
				MoveArm(-ArmLibrary_BelowPegMovement, power);
				MoveVCupToAngle();
				break;
			default:
		}

		//figure out where the position is now and return it
		switch (position) {
					case 4:
						position = 3;
						break;
					case 3:
						position = 2;
						break;
					case 2:
						position = 1;
						break;
					case 1:
						position = 1;
						break;
					default:
		}
	} else {
		ArmLibrary_FourBarTrackingFailure = true;
		MoveArm(0.1, power);
	}
	return position;
}
