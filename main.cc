#include "systemc.h"
#include "traffic.h" //including header files
#include "monitor.h"
#include "driver.h"

int sc_main(int argc, char*argv[])
{
	sc_signal<bool> s_greenNL, s_amberNL, s_redNL; //signals, North Lane
	sc_signal<bool> s_greenEL, s_amberEL, s_redEL; //signals, East Lane
	sc_signal<bool> s_greenSL, s_amberSL, s_redSL; //signals, South Lane
	sc_signal<bool> s_greenWL, s_amberWL, s_redWL; //signals, west Lane

	sc_trace_file *tf;                             //trace file(pointer), to trace signals
	tf=sc_create_vcd_trace_file("Display");        //create VCD trace. Traffic Light Display

	sc_trace(tf, s_greenNL, "GreenNL");            //signals to be traced.
	sc_trace(tf, s_amberNL, "AmberNL");
	sc_trace(tf, s_redNL, "RedNL");

	sc_trace(tf, s_greenEL, "GreenEL");
	sc_trace(tf, s_amberEL, "AmberEL");
	sc_trace(tf, s_redEL, "RedEL");

	sc_trace(tf, s_greenSL, "GreenSL");
	sc_trace(tf, s_amberSL, "AmberSL");
	sc_trace(tf, s_redSL, "RedSL");

	sc_trace(tf, s_greenWL, "GreenWL");
	sc_trace(tf, s_amberWL, "AmberWL");
	sc_trace(tf, s_redWL, "RedWL");

	traffic_Lights tra("traffic");
	monitor mon("monitor");
	driver dri("driver");

	tra.greenNL(s_greenNL);       //below is binding, named
	tra.amberNL(s_amberNL);
	tra.redNL(s_redNL);

	tra.greenEL(s_greenEL);
	tra.amberEL(s_amberEL);
	tra.redEL(s_redEL);

	tra.greenSL(s_greenSL);
	tra.amberSL(s_amberSL);
	tra.redSL(s_redSL);

	tra.greenWL(s_greenWL);
	tra.amberWL(s_amberWL);
	tra.redWL(s_redWL);


	dri.d_greenNL(s_greenNL);
	dri.d_amberNL(s_amberNL);
	dri.d_redNL(s_redNL);

	dri.d_greenEL(s_greenEL);
	dri.d_amberEL(s_amberEL);
	dri.d_redEL(s_redEL);

	dri.d_greenSL(s_greenSL);
	dri.d_amberSL(s_amberSL);
	dri.d_redSL(s_redSL);

	dri.d_greenWL(s_greenWL);
	dri.d_amberWL(s_amberWL);
	dri.d_redWL(s_redWL);

	mon.m_greenNL(s_greenNL);
	mon.m_amberNL(s_amberNL);
	mon.m_redNL(s_redNL);

	mon.m_greenEL(s_greenEL);
	mon.m_amberEL(s_amberEL);
	mon.m_redEL(s_redEL);

	mon.m_greenSL(s_greenSL);
	mon.m_amberSL(s_amberSL);
	mon.m_redSL(s_redSL);

	mon.m_greenWL(s_greenWL);
	mon.m_amberWL(s_amberWL);
	mon.m_redWL(s_redWL);

	sc_start(20,SC_NS);            //start simulation, for 100
	sc_close_vcd_trace_file(tf);

	return 0;
}
