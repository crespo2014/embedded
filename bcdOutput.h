
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
#include "SevenSegment.h"

class bcdOutput : public iOutput
{
	SevenSegment& sevensegment;
public:
	bcdOutput(SevenSegment& sevensegment);
	virtual ~bcdOutput();
	virtual void display(unsigned step);
};

#endif /* BCDOUTPUT_H_ */
