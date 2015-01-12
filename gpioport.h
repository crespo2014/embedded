/*
 * gpioport.h
 *
 *  Created on: 12 Jan 2015
 *      Author: lester
 */

#ifndef GPIOPORT_H_
#define GPIOPORT_H_

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
    }
    volatile gpio_s* const base;    // base address of gpio
public:
    enum direction_e {in, out};
    gpio(unsigned long address);

    bool readpin(uint8_t pin);
    void setpin(uint8_t pin);
    void setpins(uint32_t pin);
    void clearpins(uint32_t pin);
    void clearpin(uint8_t pin);
    void setpinDirection(direction_e d);
    void setlow(uint16_t value);
    void sethigh(uint16_t value);
    void set(uint32_t value);
    uint32_t read();
    uint16_t readlow();
    uint16_t readhigh();
};

//bcd segment needs 4 pins to set and clear individually
class bcd
{
    const uint8_t base_pin;
    gpio& gpio_;
    static const uint8_t code[11][4];   // 11 is error
public:
    bcd(uint8_t base,gpio& gpio_reg);
    void set(uint8_t value);
};


#endif /* GPIOPORT_H_ */
