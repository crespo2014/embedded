#include "buffer.h"
#include <ostream>
#include <iostream>
#include "gpioport.h"
using namespace std;

void wait()
{
	volatile int count = 10000000;
	while (count--)
		;
}
using namespace lpc2129;
int main()
{

	gpio port0(0xE0028000);
	gpio port1(0xE0028010);
	bcd bcd1(16, port1);
	motor motor1(20, port1);

	for (int i = 0; i < 100; i++)
	{
		wait();
		bcd1.set(i % 10);
		motor1.changeDirection();
	}
	return 0;
}
