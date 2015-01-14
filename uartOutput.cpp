/*
 * uartOutput.cpp
 *
 *  Created on: 14 Jan 2015
 *      Author: lester
 */

#include "uartOutput.h"

uartOutput::uartOutput(LPC2129::UART& uart) : uart(uart)
{
	// TODO Auto-generated constructor stub

}

void uartOutput::display(unsigned step)
{
	uart.write((char)(step &0xff)+0x30);
}

uartOutput::~uartOutput()
{
	// TODO Auto-generated destructor stub
}

