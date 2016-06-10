#ifndef MONITOR_H_
#define MONITOR_H_
#include "systemc.h"

SC_MODULE(monitor)
{
	sc_in<bool> m_greenNL, m_amberNL, m_redNL; //monitor signals
	sc_in<bool> m_greenEL, m_amberEL, m_redEL;
	sc_in<bool> m_greenSL, m_amberSL, m_redSL;
	sc_in<bool> m_greenWL, m_amberWL, m_redWL;

	void monitorLane()
	{
		cout <<"At "<<sc_time_stamp()<<" state is: GreenNL: AmberNL: RedNL: "<<m_greenNL
				<<m_amberNL<<m_redNL<<endl;
		cout <<"At "<<sc_time_stamp()<<" state is: GreenEL: AmberEL: RedEL: "<<m_greenEL
				<<m_amberEL<<m_redEL<<endl;
		cout <<"At "<<sc_time_stamp()<<" state is: GreenSL: AmberSL: RedSL: "<<m_greenSL
				<<m_amberSL<<m_redSL<<endl;
		cout <<"At "<<sc_time_stamp()<<" state is: GreenWL: AmberWL: RedWL: "<<m_greenWL
				<<m_amberWL<<m_redWL<<endl;
	}

SC_CTOR(monitor)
{
	SC_METHOD(monitorLane);
	sensitive<< m_greenNL<<m_amberNL<<m_redNL;
	sensitive<< m_greenEL<<m_amberEL<<m_redEL;
	sensitive<< m_greenSL<<m_amberSL<<m_redSL;
	sensitive<< m_greenWL<<m_amberWL<<m_redWL;
}
};

#endif /* MONITOR_H_ */

