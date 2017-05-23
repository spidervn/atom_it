/*
 * Stopwatch.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: sunt1
 */

#include "Stopwatch.h"
#include <time.h>
#include <stdio.h>

Stopwatch::Stopwatch() {
	reset();
}


void Stopwatch::reset()
{
	starttime = clock();
}

void Stopwatch::stopNprint(const char* szText)
{
	clock_t runtime = clock() - starttime;
	printf("[Rutime=%d millisecs] %s\r\n", runtime, szText);
}
