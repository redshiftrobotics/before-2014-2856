#include "SensorUpdate.h"
#include "../common/GyroLibrary.h"

void Initialize() {
	StartGyro();
	StartTask(sensorUpdate);
}
