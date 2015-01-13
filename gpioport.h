
#ifndef GPIOPORT_H_
#define GPIOPORT_H_

#include "stdint.h"

//@todo ping number to be enum


namespace lpc2129
{
// 32 bits gpio
// output register can be read back
class gpio
{
	struct gpio_s
	{
		uint32_t data;
		uint32_t setpin;
		uint32_t direction;
		uint32_t cleatpin;
	};
	volatile gpio_s* const base;    // base address of gpio
	gpio(const gpio&);
	gpio& operator=(const gpio&);
public:
	enum direction_e
	{
		in, out
	};
	gpio(unsigned long address);

	bool readpin(unsigned pin);
	void setpin(unsigned pin);
	void clearpin(unsigned pin);
	void setpinDirection(unsigned pin, direction_e d);
	void set(unsigned pin, bool value);

};

//bcd segment needs 4 pins to set and clear individually
class bcd
{
	const uint8_t base_pin;
	gpio& gpio_;
public:
	bcd(uint8_t base, gpio& gpio_reg);
	void set(unsigned value);
};

class uart
{
	struct uart_s
	{

	};
};

}

#endif /* GPIOPORT_H_ */
