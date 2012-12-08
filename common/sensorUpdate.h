#include "GyroLibrary.h"

task sensorUpdate {
	while(true)
	{
		nxtDisplayString(4, "%f", ReturnGyroDegrees());
		UpdateGyro();
	}
}
