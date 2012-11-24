void MoveConstantSpeedMotorD(int speed, int MaxTime)
{
	ClearTimer(T1);
	while(time1[T1] < Maxtime)
	{

		float kp = .2;
		float targetRPMs = speed*1.4;
		float powerlevel = speed;
		float CurrentMotorPosition = 0;
		float PreviousMotorPosition = 0;
		float ChangeMotorPosition = 0;
		float CurrentTime = 0;
		float PreviousTime = 0;
		float ChangeTime = 0;
		float error = 0;
		float MotorSpeed = 0;

		CurrentMotorPosition = nMotorEncoder[motorD];
		ChangeMotorPosition = abs(CurrentMotorPosition - PreviousMotorPosition);
		CurrentTime = nPgmTime;
		ChangeTime = CurrentTime - PreviousTime;
		MotorSpeed = ChangeMotorPosition/ChangeTime*1000/1440*60;
		error = targetRPMs - MotorSpeed;
		powerlevel = powerlevel + kp*error;
		motor[motorD] = -powerlevel;
		PreviousMotorPosition = CurrentMotorPosition;
		PreviousTime = CurrentTime;
		nxtDisplayString(2, "powerlevelF: %f", powerlevel);


		writeDebugStreamLine("Actual: %3.0f", MotorSpeed);
		writeDebugStreamLine("Setpoint: %3.0f", targetRPMs);
		writeDebugStreamLine("powerlevel: %3.0f", powerlevel);
	}
}

void MoveConstantSpeedMotorE(int speed, int MaxTime)
{
	ClearTimer(T1);
	while(time1[T1] < Maxtime)
	{
		float kp = .2;
		float targetRPMs = speed*1.4;
		float powerlevel = speed;
		float CurrentMotorPosition = 0;
		float PreviousMotorPosition = 0;
		float ChangeMotorPosition = 0;
		float CurrentTime = 0;
		float PreviousTime = 0;
		float ChangeTime = 0;
		float error = 0;
		float MotorSpeed = 0;


		CurrentMotorPosition = nMotorEncoder[motorE];
		ChangeMotorPosition = abs(CurrentMotorPosition - PreviousMotorPosition);
		CurrentTime = nPgmTime;
		ChangeTime = CurrentTime - PreviousTime;
		MotorSpeed = ChangeMotorPosition/ChangeTime*1000/1440*60;

		error = targetRPMs - MotorSpeed;
		powerlevel = powerlevel + kp*error;
		motor[motorE] = powerlevel;
		PreviousMotorPosition = CurrentMotorPosition;
		PreviousTime = CurrentTime;

		nxtDisplayString(1, "powerlevelE: %f", powerlevel);

		writeDebugStreamLine("Actual: %3.0f", MotorSpeed);
		writeDebugStreamLine("Setpoint: %3.0f", targetRPMs);
		writeDebugStreamLine("powerlevel: %3.0f", powerlevel);
	}
}
