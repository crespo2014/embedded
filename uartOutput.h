/*
 * uartOutput.h
 *
 *  Created on: 14 Jan 2015
 *      Author: lester
 */

#ifndef UARTOUTPUT_H_
#define UARTOUTPUT_H_

#include "ioutput.h"

class uartOutput: public iOutput
{
	UART& uart;
public:
	uartOutput(UART& uart);
	virtual void display(unsigned step);
	virtual ~uartOutput();
};

#endif /* UARTOUTPUT_H_ */
