#include "SensorUpdate.h"
#include "../CommonLibraries/GyroLibrary.h"

void Initialize() {
	StartGyro();
	StartTask(sensorUpdate);
}
