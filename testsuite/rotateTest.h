#include "../common/initialize.h"

#include "../common/TurnLibrary.h"

void rotateTest()
{
	initialize();
	RotateAmount(45);
	Sleep(1000);
	RotateAmount(45);
	Sleep(1000);
	RotateAmount(90);
	for (int i = 0; i < 36; i++) {
		 RotateAmount(10);
		 Sleep(1000);
	}
}
