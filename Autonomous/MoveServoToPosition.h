#ifndef __MOVE_SERVO_TO_POSITION_H__
#define __MOVE_SERVO_TO_POSITION_H__

void MoveServoToPosition(int Degrees)
{
	servo[servo3] = Degrees + 130 * 1.422222;
}

#endif // ifndef __MOVE_SERVO_TO_POSITION_H__
