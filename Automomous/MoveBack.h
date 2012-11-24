void MoveBack()
{
	motor[motorD] = (20 + 10);
  motor[motorE] = -20;
  Sleep(800);
  motor[motorD] = 0;
  motor[motorE] = 0;
}
