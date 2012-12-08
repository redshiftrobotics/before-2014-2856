#include "sensorUpdate.h"
#include "GyroLibrary.h"

void initialize() {
	StartGyro();
	StartTask(sensorUpdate);
}
