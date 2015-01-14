/*
 * uartOutput.cpp
 *
 *  Created on: 14 Jan 2015
 *      Author: lester
 */

#include "uartOutput.h"

uartOutput::uartOutput(UART& uart) : uart(uart)
{
	// TODO Auto-generated constructor stub

}

void uartOutput::display(unsigned step)
{
	uart.write(step & 0xff);
}

uartOutput::~uartOutput()
{
	// TODO Auto-generated destructor stub
}

