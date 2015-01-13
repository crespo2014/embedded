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

	enum WashProgrammer::step_e was1[]={WashProgrammer::rinse,WashProgrammer::spin};
	WashProgrammer	washer(bcd1,was1,2);
	washer.run();

	return 0;
}
