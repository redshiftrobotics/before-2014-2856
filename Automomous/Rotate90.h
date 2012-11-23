#ifndef __ROTATE_90_H__
#define __ROTATE_90_H__

void Rotate90()
{
	motor[motorD] = 0;
	motor[motorE] = 0;
	Sleep(300);
	motor[motorD] = 50;
	motor[motorE] = 50;
	Sleep(700);
	motor[motorD] = 0;
	motor[motorE] = 0;
}

#endif // ifndef __ROTATE_90_H__