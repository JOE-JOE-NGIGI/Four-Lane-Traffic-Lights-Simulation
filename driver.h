/*
 * driver.h
 *
 *  Created on: Feb 4, 2015
 *      Author: joe--ngigi
 */
#ifndef DRIVER_H_
#define DRIVER_H_
#include "systemc.h"

SC_MODULE(driver)
{
	sc_out<bool> d_greenNL,d_amberNL,d_redNL,d_greenEL,d_amberEL,d_redEL,d_greenSL,d_amberSL,d_redSL;
	sc_out<bool> d_greenWL,d_amberWL,d_redWL;//inputs

//FOR NORTH LANE
void driveGreenNL()// this is a process
{
	for(int i=0; i<10;i++)
	{
		d_greenNL.write((bool)true);
		wait(2,SC_NS);
		d_greenNL.write((bool)false);
		wait(8,SC_NS);
	}
}

void driveAmberNL()// this is a process
{
	d_amberNL.write((bool)false);
	wait(2,SC_NS);
	for(int i=0; i<10;i++)
	{
		d_amberNL.write((bool)true);
		wait(0.5,SC_NS);
		d_amberNL.write((bool)false);
		wait(9.5,SC_NS);
	}
}

void driveRedNL()// this is a process
{
	d_redNL.write((bool)false);
	wait(2.5,SC_NS);
	for(int i=0; i<10;i++)
	{
		d_redNL.write((bool)true);
		wait(7.5,SC_NS);
		d_redNL.write((bool)false);
		wait(2.5,SC_NS);
	}
}

//FOR EAST LANE
void driveGreenEL()// this is a process
{
	d_greenEL.write((bool)false);
	wait(2.5,SC_NS);
	for(int i=0; i<10;i++)
	{
		d_greenEL.write((bool)true);
		wait(2,SC_NS);
		d_greenEL.write((bool)false);
		wait(8,SC_NS);
	}
}

void driveAmberEL()// this is a process
{
	d_amberEL.write((bool)false);
	wait(4.5,SC_NS);
	for(int i=0; i<10;i++)
	{
		d_amberEL.write((bool)true);
		wait(0.5,SC_NS);
		d_amberEL.write((bool)false);
		wait(9.5,SC_NS);
	}
}

void driveRedEL()// this is a process
{
	d_redEL.write((bool)true);
	wait(2.5,SC_NS);
	d_redEL.write((bool)false);
	wait(2.5,SC_NS);
	for(int i=0; i<10;i++)
	{
		d_redEL.write((bool)true);
		wait(7.5,SC_NS);
		d_redEL.write((bool)false);
		wait(2.5,SC_NS);
	}
}

//FOR SOUTH LANE
void driveGreenSL()// this is a process
{
	d_greenSL.write((bool)false);
	wait(5,SC_NS);
	for(int i=0; i<10;i++)
	{
		d_greenSL.write((bool)true);
		wait(2,SC_NS);
		d_greenSL.write((bool)false);
		wait(8,SC_NS);
	}
}

void driveAmberSL()// this is a process
{
	d_amberSL.write((bool)false);
	wait(7,SC_NS);
	for(int i=0; i<10;i++)
	{
		d_amberSL.write((bool)true);
		wait(0.5,SC_NS);
		d_amberSL.write((bool)false);
		wait(9.5,SC_NS);
	}
}

void driveRedSL()// this is a process
{
	d_redSL.write((bool)true);
	wait(5,SC_NS);
	d_redSL.write((bool)false);
	wait(2.5,SC_NS);
	for(int i=0; i<10;i++)
	{
		d_redSL.write((bool)true);
		wait(8,SC_NS);
		d_redSL.write((bool)false);
		wait(2,SC_NS);
	}
}

//FOR WEST LANE
void driveGreenWL()// this is a process
{
	d_greenWL.write((bool)false);
	wait(7.5,SC_NS);
	for(int i=0; i<10;i++)
	{
		d_greenWL.write((bool)true);
		wait(2,SC_NS);
		d_greenWL.write((bool)false);
		wait(8,SC_NS);
	}
}

void driveAmberWL()// this is a process
{
	d_amberWL.write((bool)false);
	wait(9.5,SC_NS);
	for(int i=0; i<10;i++)
	{
		d_amberWL.write((bool)true);
		wait(0.5,SC_NS);
		d_amberWL.write((bool)false);
		wait(9.5,SC_NS);
	}
}

void driveRedWL()// this is a process
{
	d_redWL.write((bool)true);
	wait(7.5,SC_NS);
	d_redWL.write((bool)false);
	wait(2.5,SC_NS);
	for(int i=0; i<10;i++)
	{
		d_redWL.write((bool)true);
		wait(8,SC_NS);
		d_redWL.write((bool)false);
		wait(2,SC_NS);
	}
}

SC_CTOR(driver)
{
	SC_THREAD (driveGreenNL);//process is called here
	SC_THREAD (driveAmberNL);
	SC_THREAD (driveRedNL);

	SC_THREAD (driveGreenEL);//process is called here
	SC_THREAD (driveAmberEL);
	SC_THREAD (driveRedEL);

	SC_THREAD (driveGreenSL);//process is called here
	SC_THREAD (driveAmberSL);
	SC_THREAD (driveRedSL);

	SC_THREAD (driveGreenWL);//process is called here
	SC_THREAD (driveAmberWL);
	SC_THREAD (driveRedWL);
}
};




#endif
