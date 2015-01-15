
/*
 * ioutput.h
 *
 *  Created on: 14 Jan 2015
 *      Author: lester
 */

#ifndef IOUTPUT_H_
#define IOUTPUT_H_


class iOutput
{
public:
	virtual void display(unsigned step) = 0;
protected:
	~iOutput(){};
};


#endif /* IOUTPUT_H_ */
