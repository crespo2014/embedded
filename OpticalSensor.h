/*
 * OpticalSensor.h
 *
 *  Created on: 15 Jan 2015
 *      Author: lester
 */

#ifndef OPTICALSENSOR_H_
#define OPTICALSENSOR_H_

#include <ctime>

#include "gpioport.h"

class OpticalSensor
{
	lpc2129::gpio& port_;
	unsigned pin;
public:
	OpticalSensor(lpc2129::gpio& port,unsigned pin);
	virtual ~OpticalSensor();
	bool waitTransitions(unsigned count,unsigned timeout_ms);
};

#endif /* OPTICALSENSOR_H_ */
