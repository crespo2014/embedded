/*
 * MotorController.cpp
 *
 *  Created on: 15 Jan 2015
 *      Author: lester
 */

#include "MotorController.h"
#include "MotorFailedException.h"

MotorController::MotorController(lpc2129::motor& m, OpticalSensor& sensor) : motor_(m),sensor_(sensor)
{
}

MotorController::~MotorController()
{
	// TODO Auto-generated destructor stub
}

void MotorController::On()
{
	motor_.on();
	if (!sensor_.waitTransitions(10,1000))
		throw MotorFailedException();
}

void MotorController::Off()
{
	motor_.off();
	if (sensor_.waitTransitions(4,1000))
		throw MotorFailedException();
}
