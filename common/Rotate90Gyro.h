void Rotate90()
{
	if (abs(ReturnGyroValue()) < 88 && abs(ReturnGyroValue()) > 92)
	{
		motor[motorD] = 30;
		motor[motorF] = 30;
	}
}
