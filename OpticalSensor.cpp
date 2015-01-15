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

}

OpticalSensor::~OpticalSensor()
{
	// TODO Auto-generated destructor stub
}

bool OpticalSensor::waitTransitions(unsigned count, unsigned timeout_ms)
{
	bool v = port_.readpin(pin);
	std::clock_t t = std::clock();
	unsigned tm_ms = 0;
	while (count && tm_ms < timeout_ms)
	{
		tm_ms = (float) (clock() - t) * 1000 / CLOCKS_PER_SEC;
		if (v != port_.readpin(pin))
		{
			count--;
			v = !v;
		}
	}
	return (count == 0);
}
