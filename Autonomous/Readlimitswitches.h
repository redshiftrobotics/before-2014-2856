#ifndef __READLIMITSWITCHES_H__
#define __READLIMITSWITCHES_H__

int readlimitswitches()
{
	limitswitch1 = HTPBreadADC(LimitSwitches, 0, 10);		//A0 input
	limitswitch2 = HTPBreadADC(LimitSwitches, 2, 10);		//A2 input
	if(limitswitch1 < 512) {return 1;}
	else if(limitswitch2 < 512) {return 2;}
	else return 0;
}

#endif // ifndef __READLIMITSWITCHES_H__
