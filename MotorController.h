/*
 * MotorController.h
 *
 *  Created on: 15 Jan 2015
 *      Author: lester
 */

#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#include "OpticalSensor.h"
#include "gpioport.h"

class MotorController
{
	lpc2129::motor& motor_;
	OpticalSensor& sensor_;
public:
	MotorController(lpc2129::motor& m,OpticalSensor& sensor);
	virtual ~MotorController();
	void On();
	void Off();
};

#endif /* MOTORCONTROLLER_H_ */
