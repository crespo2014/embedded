/*
 * bcdOutput.h
 *
 *  Created on: 14 Jan 2015
 *      Author: lester
 */

#ifndef BCDOUTPUT_H_
#define BCDOUTPUT_H_

#include "gpioport.h"
#include "ioutput.h"

class bcdOutput : public iOutput
{
	lpc2129::bcd& sevensegment;
public:
	bcdOutput(lpc2129::bcd& sevensegment);
	virtual ~bcdOutput();
	virtual void display(unsigned step);
};

#endif /* BCDOUTPUT_H_ */
