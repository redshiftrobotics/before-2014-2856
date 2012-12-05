void MoveForward(int sleepInterval)
{
	motor[motorD] = -(20 + 10);
  motor[motorE] = 20;
  Sleep(sleepInterval);
  motor[motorD] = 0;
  motor[motorE] = 0;

}
