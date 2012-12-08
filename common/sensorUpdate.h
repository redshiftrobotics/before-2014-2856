#include "GyroLibrary.h"

task sensorUpdate {
	while(true)
	{
		UpdateGyro();
	}
}
