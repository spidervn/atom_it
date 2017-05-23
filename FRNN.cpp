/*
 * FRNN.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: ducvd
 */

#include "FRNN.h"
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <iostream>

#define MAX_PROBLEM 100000

class FRNN::Impl
{
public:

	void genTestData(double* d,int n)
	{
		int MAXVALUE = 1999;

		for (int i=0;i<n;i++) {
			d[i] = ((double)rand()/RAND_MAX)*MAXVALUE;
		}
	}

	void dummy1d()
	{
		double d[MAX_PROBLEM];
		double r = 0.5;
		int n = MAX_PROBLEM;
		int count = 0;

		genTestData(d,n);
		d[0] =1;
		d[1] = 1;
		clock_t starttime = clock();

		printf("[DUMMY]\r\n");
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
			{
				if (fabs(d[i] - d[j]) <= r)
				{
					// printf("(%d,%d) = (%f,%f)\r\n", i,j,d[i], d[j]);
					count ++;
				}
			}

		clock_t runTime = clock() - starttime;
		printf ("\r\nCount = %d, Runtime: %d clicks (%f seconds).\n",count, runTime,((float)runTime)/CLOCKS_PER_SEC);
	}

	void bucket1d()
	{
		double d[MAX_PROBLEM];
		double r = 0.1;
		int n = MAX_PROBLEM;
		int count = 0;

		printf("%d\r\n",sizeof(long));
		printf("%d\r\n",sizeof(int));

		genTestData(d,n);
		std::map<long,std::list<int>*> hash;

		printf("[BUCKET]\r\n");
		clock_t starttime = clock();

		for (int i=0;i<n;i++)
		{
			long idx = trunc(d[i]/r);
			addMap(hash,idx,i);
		}

		for (int i=0;i<n;i++)
		{

			long idx = trunc(d[i]/r);

			std::list<int>::iterator it;

			for (it = hash[idx]->begin();it!=hash[idx]->end();it++)
			{
				if (*it < i)
				{
					count++;
					//if (count < 100)
					//	printf("(%d,%d)=(%f,%f)",i,*it,d[i],d[*it]);
				}
			}

			if (hash[idx+1] != NULL)
				for (it = hash[idx+1]->begin();it!=hash[idx+1]->end();it++)
					{
						if (*it < i)
						{
							// printf("(%d,%d)=(%f,%f)",i,*it,d[i],d[*it]);
							count++;
							//if (count < 100)
							//	printf("(%d,%d)=(%f,%f)",i,*it,d[i],d[*it]);
						}
					}
		}

		clock_t runTime = clock() - starttime;
		printf ("\r\nCount = %d, Runtime: %d clicks (%f seconds).\n",count, runTime,((float)runTime)/CLOCKS_PER_SEC);
	}

	void bucket2d()
	{
		int n = MAX_PROBLEM;
		double x[MAX_PROBLEM];
		double y[MAX_PROBLEM];
		bool mark[MAX_PROBLEM];	// true = selection; false - not selection
		double r=11;
		int count = 0;
		clock_t starttime = clock();
		clock_t runtime;

		genTestData(x,n);
		genTestData(y,n);

		x[0] = 0; y[0] = 0;
		x[1] = 10; y[1] = 10;
		x[2] = 20; y[2] = 0;
		x[3] = 30; y[3] = 0;
		x[4] = 40; y[4] = 0;
		x[5] = 50; y[5] = 0;

		std::map<std::string,std::list<int>*> hash;

		printf("[BUCKET2D].Start\r\n");
		for (int i=0;i<n;i++)
		{
			long cellx = trunc(x[i]/r);
			long celly = trunc(y[i]/r);

			std::string id = getHash(cellx,celly);
			addMap(hash, getHash(cellx, celly), i);
			mark[i] = true;
		}

		for (int i=0;i<n;i++)
			if (mark[i])
			{
				long cellx = trunc(x[i]/r);
				long celly = trunc(y[i]/r);

				std::list<int>::iterator it;

				std::string cellid = getHash(cellx,celly);
				std::string cellnext = getHash(cellx+1,celly);
				std::string cellnext2 = getHash(cellx,celly+1);

				if (hash[cellid] != NULL)
				{
					std::list<int>* pList = hash[cellid];
					for (it=pList->begin();it!=pList->end();it++)
						if (*it != i)
						{
							mark[*it] = false; // reduce point
							//printf("Removed %d\r\n", *it);
						}
				}

				if (hash[cellnext] != NULL)
				{
					std::list<int>* pList = hash[cellnext];
					for (it=pList->begin();it!=pList->end();it++)
						if (*it != i)
						{
							mark[*it] = false; // reduce point
							//printf("Removed %d\r\n", *it);
						}
				}

				if (hash[cellnext2] != NULL)
				{
					std::list<int>* pList = hash[cellnext2];
					for (it=pList->begin();it!=pList->end();it++)
						if (*it != i)
						{
							mark[*it] = false; // reduce point
							//printf("Removed %d\r\n", *it);
						}
				}
			}

		for (int i=0;i<n;i++)
			if (mark[i])
				count++;

		runtime = clock() - starttime;
		printf("Result %d/%d, runtime = %d ticks", count,n, runtime);
	}

	std::string getHash(long cellx, long celly)
	{
		char szBuf[32];
		sprintf(szBuf,"%d+%d", cellx, celly);

		return std::string(szBuf);
	}

	void idol()
	{
		int n = MAX_PROBLEM;
		double d[MAX_PROBLEM];
		int count;

		genTestData(d,n);
		clock_t starttime = clock();

		printf("[IDOL]\r\n");
		for (int i=0;i<n;i++)
			if (d[i] > 0)
				count++;

		clock_t runTime = clock() - starttime;
				printf ("\r\nCount = %d, Runtime: %d clicks (%f seconds).\n",count, runTime,((float)runTime)/CLOCKS_PER_SEC);
	}

private:
	void addMap(std::map<long,std::list<int>*> &hash, long id, int value)
	{
		std::list<int>* pIdx = hash[id];

		if (!pIdx)
		{
			hash[id] = new std::list<int>();
		}

		hash[id]->push_back(value);
	}

	void addMap(std::map<std::string,std::list<int>*> &hash, std::string id, int value)
		{
			std::list<int>* pIdx = hash[id];

			if (!pIdx)
			{
				hash[id] = new std::list<int>();
			}

			hash[id]->push_back(value);
		}
};

FRNN::FRNN() : _pImpl(new Impl()) {
}

void FRNN::Run()
{
	//_pImpl->dummy1d();
	// _pImpl->bucket1d();
	// _pImpl->idol();
	_pImpl->bucket2d();
}
