#include "buffer.h"
#include <ostream>
#include <iostream>
#include "gpioport.h"
#include "SevenSegment.h"
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
	SevenSegment bcd1(16, port1);
	motor motor1(20, port1);
//
//	WMS wms(bcd1,motor1);
//	wms.run();
//	wms.changeProgram();
//	wms.run();
//	wms.changeProgram();
//	wms.run();
//	wms.changeProgram();
//	wms.run();
//	wms.changeProgram();
//	wms.run();

	return 0;
}
