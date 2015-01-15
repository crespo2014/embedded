/*
 * MotorFailedException.h
 *
 *  Created on: 15 Jan 2015
 *      Author: lester
 */

#ifndef MOTORFAILEDEXCEPTION_H_
#define MOTORFAILEDEXCEPTION_H_

#include <exception>

class MotorFailedException: public std::exception
{
public:
	MotorFailedException();
	virtual ~MotorFailedException()  throw();
	virtual const char* what() const throw() 
	{
		return "Motor failed to start/stop";
	}
};

#endif /* MOTORFAILEDEXCEPTION_H_ */
