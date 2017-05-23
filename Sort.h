/*
 * Sort.h
 *
 *  Created on: Nov 18, 2013
 *      Author: sunt1
 */

#ifndef SORT_H_
#define SORT_H_

#include <memory>

class Sort {
public:
	Sort();
	virtual ~Sort();
	void Run();

private:
	class Impl;
	std::auto_ptr<Impl> _pImp;
};

#endif /* SORT_H_ */
