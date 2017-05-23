/*
 * FRNN.h
 *
 *  Created on: Nov 18, 2013
 *      Author: sunt1
 */

#ifndef FRNN_H_
#define FRNN_H_

#include <memory>

/*================================================================================
 * Author: ducvd
 * Fixed Radius Near Neighbor
 *================================================================================*/

class FRNN {
public:
	FRNN();
	void Run();

private:
	class Impl;
	std::auto_ptr<Impl> _pImpl;
};

#endif /* FRNN_H_ */
