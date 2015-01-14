/*
 * bcdOutput.cpp
 *
 *  Created on: 14 Jan 2015
 *      Author: lester
 */

#include "bcdOutput.h"

bcdOutput::bcdOutput(lpc2129::bcd& sevensegment): sevensegment(sevensegment)
{
	// TODO Auto-generated constructor stub

}

bcdOutput::~bcdOutput()
{
	// TODO Auto-generated destructor stub
}

void bcdOutput::display(unsigned step)
{
	sevensegment.set(step);
}
