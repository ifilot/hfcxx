/*
 * clock.h
 *
 * Author: Ivo Filot
 */

#ifndef _CLOCK_H
#define _CLOCK_H

#include<sys/time.h>
#include<cstddef>

class Clock{
	private:
	struct timeval time1,time2;
	long mtime, seconds, useconds;
	public:
	Clock(); /* default constructor */
	void tic();	/* starts / resets the clock */
	void toc();	/* pauses the clock */
	double passed(); /* returns the time in seconds */
};

#endif //_CLOCK_H
