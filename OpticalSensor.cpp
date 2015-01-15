/*
 * OpticalSensor.cpp
 *
 *  Created on: 15 Jan 2015
 *      Author: lester
 */

#include "OpticalSensor.h"

using namespace std;

OpticalSensor::OpticalSensor(lpc2129::gpio& port, unsigned pin) :
		port_(port), pin(pin)
{
	port_.setpinDirection(pin,lpc2129::gpio::in);
}

OpticalSensor::~OpticalSensor()
{
	// TODO Auto-generated destructor stub
}

bool OpticalSensor::waitTransitions(unsigned count, unsigned timeout_ms)
{
	bool v = port_.readpin(pin);
	unsigned retries = 0;
//	std::clock_t t = clock();
//	unsigned tm_ms = 0;
	while (count && retries < 1*1000*1000)
	{
         //   clock_t t2 = clock();
		//tm_ms = ((float) (clock() - t)) * 1000 / CLOCKS_PER_SEC;
		if (v != port_.readpin(pin))
		{
			count--;
			v = !v;
		}
		retries++;
	}
	return (count == 0);
}
