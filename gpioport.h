
#ifndef GPIOPORT_H_
#define GPIOPORT_H_

#include "stdint.h"

//@todo ping number to be enum, isset function


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
// enum from 0 to 9
class bcd
{
	const uint8_t base_pin;
	gpio& gpio_;
public:
	bcd(uint8_t base, gpio& gpio_reg);
	void set(unsigned value);
};

class motor
{
	const uint8_t base_pin;
	gpio& gpio_;
	enum pins { control,direction};
public:
	enum direction_e { cw, acw};
	motor(uint8_t base, gpio& gpio_reg);
	void on();
	void off();
	void setDirection(direction_e dir);
	void changeDirection();
	direction_e getDirection();
};

//class uart
//{
//	const unsigned freq = 15 *1000*1000;
//	const uint8_t bit_len = 0;
//	const uint8_t bit_stop = 2;
//	const uint8_t bit_parity = 3;
//	const uint8_t bit_parity_type = 2;
//	const uint8_t bit_break = 6;
//	const uint8_t bit_dlab = 7;
//
//	enum word_len_e {five, sixe,seven,eight};
//	enum stop_bits {one,two};
//	enum parity_check {disable,enable};
//	enum parity_type {odd,even,force1,force0one};
//	enum dlab {dlab_off,dlab_on};
//	enum break_rx_ts {break_off,break_on};
//
//	struct uart_s
//	{
//		uint8_t rx_buff;
//		uint8_t tx_hold;
//		uint8_t it_enable;
//		uint8_t fifo_ctrl;
//		uint8_t line_ctrl;
//		uint8_t line_stat;
//		uint8_t latch_lsb;
//		uint8_t latch_msb;
//	};
//public:
//	void setBaudRate(unsigned brate);
//};

}

#endif /* GPIOPORT_H_ */
