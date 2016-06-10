#ifndef TRAFFIC_H_
#define TRAFFIC_H_
#include "systemc.h"

SC_MODULE (traffic_Lights)
{
	sc_in<bool>greenNL, amberNL, redNL; //signals
	sc_in<bool>greenEL, amberEL, redEL;
	sc_in<bool>greenSL, amberSL, redSL;
	sc_in<bool>greenWL, amberWL, redWL;

	void trafficNorthLane ()
	{
		if (greenNL==true)
		{
			amberNL==false;
			redNL==false;
		}
		else if (amberNL==true)
		{
			greenNL==false;
			redNL==false;
		}
		else
		{
			redNL==true;
			greenNL==false;
			amberNL==false;
		}
	}

	void trafficEastLane ()
	{
		if (greenEL==true)
		{
			amberEL==false;
			redEL==false;
		}
		else if (amberEL==true)
		{
			greenEL==false;
			redEL==false;
		}
		else
		{
			redEL==true;
			greenEL==false;
			amberEL==false;
		}
	}

	void trafficSouthLane ()
	{
		if (greenSL==true)
		{
			amberSL==false;
			redSL==false;
		}
		else if (amberSL==true)
		{
			greenSL==false;
			redSL==false;
		}
		else
		{
			redSL==true;
			greenSL==false;
			amberSL==false;
		}
	}

	void trafficWestLane ()
	{
		if (greenWL==true)
		{
			amberWL==false;
			redWL==false;
		}
		else if (amberWL==true)
		{
			greenWL==false;
			redWL==false;
		}
		else
		{
			redWL==true;
			greenWL==false;
			amberWL==false;
		}
	}

SC_CTOR (traffic_Lights)
{
	SC_METHOD (trafficNorthLane);
	sensitive<<greenNL<<amberNL<<redNL;
	SC_METHOD (trafficEastLane);
	sensitive<<greenEL<<amberEL<<redEL;
	SC_METHOD (trafficSouthLane);
	sensitive<<greenSL<<amberSL<<redSL;
	SC_METHOD (trafficWestLane);
	sensitive<<greenWL<<amberWL<<redWL;
}

};

#endif

