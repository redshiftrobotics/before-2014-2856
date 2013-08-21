#include "../common/GyroLibrary.h"

task sensorUpdate {
	while(true)
	{
		nxtDisplayString(1, "%f", ReturnGyroDegrees());
		UpdateGyro();
	}
}
