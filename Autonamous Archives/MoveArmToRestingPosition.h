void MoveArmToRestingPosition()
{
	motor[FourBar] = 20;
	sleep(700);
	motor[FourBar] = 0;
}
