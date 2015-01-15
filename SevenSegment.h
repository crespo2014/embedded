/*
 * SevenSegment.h
 *
 *  Created on: 14 Jan 2015
 *      Author: lester
 */

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "gpioport.h"

class SevenSegment
{
	const uint8_t base_pin;
	lpc2129::gpio& gpio_;
public:
	void set(unsigned value);
	SevenSegment(uint8_t base, lpc2129::gpio& gpio_reg);
	virtual ~SevenSegment();

	SevenSegment& operator <<(unsigned value)
	{
		set(value);
		return *this;
	}

	SevenSegment& operator <<(const char* str)
	{
		while (*str)
		{
			set(*str - 0x30);
			volatile int count = 10000000;
			while (count--)
				;
			++str;
		}
		return *this;
	}
};

#endif /* SEVENSEGMENT_H_ */
