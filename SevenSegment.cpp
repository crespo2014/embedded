/* 
 * SevenSegment.cpp
 *
 *  Created on: 14 Jan 2015
 *      Author: lester
 */

#include "SevenSegment.h"

void SevenSegment::set(unsigned value)
{
	gpio_.set(base_pin, (value & 1) != 0);
	gpio_.set(base_pin + 1, (value & 2) != 0);
	gpio_.set(base_pin + 2, (value & 4) != 0);
	gpio_.set(base_pin + 3, (value & 8) != 0);
}

SevenSegment::SevenSegment(uint8_t base, lpc2129::gpio& gpio_reg) :
		base_pin(base), gpio_(gpio_reg)
{
	gpio_reg.setpinDirection(base, lpc2129::gpio::out);
	gpio_reg.setpinDirection(base + 1, lpc2129::gpio::out);
	gpio_reg.setpinDirection(base + 2, lpc2129::gpio::out);
	gpio_reg.setpinDirection(base + 3, lpc2129::gpio::out);
}

SevenSegment::~SevenSegment()
{
	// TODO Auto-generated destructor stub
}

