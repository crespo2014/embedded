/*
 * uartOutput.h
 *
 *  Created on: 14 Jan 2015
 *      Author: lester
 */

#ifndef UARTOUTPUT_H_
#define UARTOUTPUT_H_

#include "ioutput.h"
#include "Uart.h"

class uartOutput: public iOutput
{
  LPC2129::UART& uart;
public:
  uartOutput(LPC2129::UART& uart);
	virtual void display(unsigned step);
	virtual ~uartOutput();
};

#endif /* UARTOUTPUT_H_ */
