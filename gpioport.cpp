
#include "gpioport.h"

namespace lpc2129
{
gpio::gpio(unsigned long address) :
		base(reinterpret_cast<gpio_s*>(address))
{
	base->direction = 0;
}

bool gpio::readpin(unsigned pin)
{
	return ((base->data & (0x1 << pin)) != 0);
}
void gpio::setpin(unsigned pin)
{
	base->setpin = (0x1 << pin);
}
void gpio::clearpin(unsigned pin)
{
	base->cleatpin = (0x1 << pin);
}
void gpio::setpinDirection(unsigned pin, direction_e d)
{
	if (d == out)
		base->direction |= (0x1 << pin);
	else
		base->direction &= (~(0x1 << pin));
}

void gpio::set(unsigned pin, bool value)
{
	if (value)
		setpin(pin);
	else
		clearpin(pin);
}

bcd::bcd(uint8_t base, gpio& gpio_reg) :
		base_pin(base), gpio_(gpio_reg)
{
	gpio_reg.setpinDirection(base,gpio::out);
	gpio_reg.setpinDirection(base+1,gpio::out);
	gpio_reg.setpinDirection(base+2,gpio::out);
	gpio_reg.setpinDirection(base+3,gpio::out);
}

void bcd::set(unsigned value)
{
	gpio_.set(base_pin, (value & 1) != 0);
	gpio_.set(base_pin+1, (value & 2) != 0);
	gpio_.set(base_pin+3, (value & 4) != 0);
	gpio_.set(base_pin+4, (value & 8) != 0);
//	unsigned c = 0;
//	while (c != 4)
//	{
//		gpio_.set(base_pin + c, (value & 1) != 0);
//		value >>= 1;
//		c++;
//	}
}

}

