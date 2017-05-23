//============================================================================
// Name        : AlgorithmAtom.cpp
// Author      : ducvd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "FRNN.h"
#include "Sort.h"

using namespace std;

int main() {

	srand(time(NULL));

	FRNN frnn;
	Sort sort;

	sort.Run();

	return 0;
}
