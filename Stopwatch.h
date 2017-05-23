/*
 * Stopwatch.h
 *
 *  Created on: Nov 20, 2013
 *      Author: sunt1
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include <stdlib.h>
#include <time.h>

class Stopwatch {
public:
	Stopwatch();

	void reset();

	void stopNprint(const char* szText);
private:
	clock_t starttime;
};

#endif /* STOPWATCH_H_ */
