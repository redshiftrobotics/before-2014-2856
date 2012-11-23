#ifndef __LIMITCHECK_H__
#define __LIMITCHECK_H__

void Limitcheck()
{
	if(readlimitswitches() == 1)  //IF MAX TOP LIMIT IS REACHED, GO DOWN
	{
		motor[FourBar] = 25;
	}
	else if(readlimitswitches() == 2)  // IF MAX BOTTOM LIMIT IS REACHED, DO UP
	{
		motor[FourBar] = -25;
	}
}

#endif // ifndef __LIMITCHECK_H__