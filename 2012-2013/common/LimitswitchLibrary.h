//liblimitswitch
//written by Alex Jordan

bool bottomLimitSwitchTouched()
{
	int value;
	//FIXME
	//return a bogus result until we get actual hardware
	/*
	value = HTPBreadADC(HTPB, 0, 10);
	if (value > 512) {
		//the limitswitch has been triggered
		return true;
	}
	*/
	return false;
}

bool topLimitSwitchTouched()
{
	int value;
	//FIXME
	//return a bogus result until we get actual hardware
	/*
	value = HTPBreadADC(HTPB, 0, 10);
	if (value > 512) {
		//the limitswitch has been triggered
		return true;
	}
	*/
	return false;
}
