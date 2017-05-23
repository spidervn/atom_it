/*
 * Sort.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: ducvd
 */

#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stopwatch.h"
#include <math.h>
#include <conio.h>

#define MAX_SORT 100000
#define MAX_HEAP_DEGREE 10

#define themax(a,b) (a) > (b) ? (a) : (b)
#define themin(a,b) (a) > (b) ? (b) : (a)

class Sort::Impl
{
public:
	void insertion()
	{
		int a[MAX_SORT];
		int n = MAX_SORT;
		Stopwatch sw;

		// a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;

		generateData(a,n);
		sw.reset();
		printf("[Insertion sort begin] size=%d\r\n",n);

		for (int i=0;i<n;i++)
		{
			for (int j=0;j<i;j++)
			{
				if (a[j] >= a[i])
				{
					for (int k=i;k>j;k--)
					{
						// swap a[k],a[k-1]
						int tmp = a[k];
						a[k] = a[k-1];
						a[k-1] = tmp;
					}

					break;
				}
			}
		}

		checkResult(a,n);
		sw.stopNprint("Insertion sort finish\r\n");
	}

	void insertion_imprv()
		{
			int a[MAX_SORT];
			int buffer[MAX_SORT];
			int n = MAX_SORT;
			Stopwatch sw;

			// a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;

			generateData(a,n);
			sw.reset();
			printf("[Insertion sort imprv begin] size=%d\r\n",n);

			// printArray(a,n);
			for (int i=0;i<n;i++)
			{
				for (int j=0;j<i;j++)
				{
					if (a[j] >= a[i])
					{
						// swap by memcopy
						int tmp = a[i];
						memcpy(buffer,a + j, (i-j)*sizeof(int));
						memcpy(a+j+1,buffer, (i-j)*sizeof(int));
						a[j] = tmp;
						break;
					}
				}
			}

			// printArray(a,n);
			checkResult(a,n);
			sw.stopNprint("Insertion sort imprv finish\r\n");
		}

	void bubbleSort_topDown()
	{
		int a[] = {1,3,2,1,1,4,3};
		int n = sizeof(a)/sizeof(int);
		int top = n-1;
		bool bNext;
		do {
			bNext = false;
			for (int i=0;i<top;i++)
			{
				if (a[i] > a[i+1])
				{
					int swap = a[i];
					a[i] = a[i+1];
					a[i+1] = swap;

					bNext = true;
				}
			}

			top --;
		} while (bNext && top > 0);

		printf("[BubbleSort.TopDown] DONE\r\n");
		printArray(a,n);
	}

	void bubbleSort_bottomUp()
	{
		int a[] = {1,1,1,1,1,1,-1,2};
		int n = sizeof(a)/sizeof(int);
		int loop = 0;
		bool bNext;

		do
		{
			bNext = false;
			for (int i=n-1;i>loop;i--)
			{
				if (a[i] < a[i-1])
				{
					int swap = a[i-1];
					a[i-1] = a[i];
					a[i] = swap;
					bNext = true;
				}
			}

			loop++;
		} while (bNext && loop < n);

		printf("[BubbleSort.BottomUp] DONE\r\n");
		printArray(a,n);
	}

	void heap() 
	{
		int a[MAX_SORT];
		int n = MAX_SORT;
		int ROOT = 0;
		int parent, l, r;
		int eidx;
		Stopwatch sw;

		/*================================================================================
			1) build tree
				Parent > childs
				p > = max(p.left,p.right)
			2) 
		 *================================================================================*/

		generateData(a,n);
		sw.reset();
		printf("Heap begin: size = %d\r\n",n);

		// Build heap
		for (int i=0;i<n;i++)  
		{
			parent = heap_parent(i,i+1);	
			eidx = i;

			while (parent >= 0 && a[parent] < a[eidx])
			{
				int tmp = a[parent];
				a[parent] = a[eidx];
				a[eidx] = tmp;

				eidx = parent;
				parent = heap_parent(eidx,i+1);
			}
		}

		for (int i=0;i<n;i++) {

			int rightmost = n-1-i;
			int newN = n-i-1;

			int tmp = a[ROOT];
			a[ROOT] = a[rightmost];
			a[rightmost] = tmp;

			// re-index tree/ top-down approach
			int newRoot = ROOT;

			do 
			{
				l = heap_child_left(newRoot,newN);
				r = heap_child_right(newRoot, newN);
				int imax = l;

				if (l<=0)
					break;

				if (l>=0 && r>=0 && a[l] < a[r])
					imax = r;

				if (a[newRoot] < a[imax])
				{
					myswap(&a[newRoot],&a[imax]);
					newRoot = imax;
				}
				else 
					break;
			} while (true);
		}

		checkResult(a,n);
		sw.stopNprint("Heap stop");		
	}

	void k_heap(int degree) 
	{
		if (degree < 2 || degree > MAX_HEAP_DEGREE)
			return;
		/*
			1./ Build tree
			2./ Sort heap n-
		 */
		int a[] = {1,3,2,4};
		int n = 4;
		int enumId;
		int childs[MAX_HEAP_DEGREE];
		int countchild;

		// generateData(a,n);

		printf("Heap imprv, degree=%d, size=%d\r\n",degree,n);
		Stopwatch sw;
		sw.reset();

		for (int i=0;i<n;i++) 
		{
			int newN = i+1;
			int parent = k_heap_parent(i, newN, degree);
			int enumId = i;

			while (a[parent] < a[enumId]) 
			{
				myswap(&a[parent],&a[i]);
				enumId = parent;
				parent = k_heap_parent(i,newN,degree);
			}
		}

		printArray(a,n);
		for (int i=0;i<n;i++) 
		{
			int newN = n - i - 1;
			int removedid = n-i-1;

			enumId = 0;
			myswap(&a[enumId],&a[removedid]);

			do
			{
				k_heap_getchild(enumId, newN, degree, childs, countchild );

				if (countchild > 0)
				{
					int imax = childs[0];

					for (int j=1;j<countchild;j++)
						if (a[imax] < a[childs[j]]) 
						{
							imax = childs[j];
						}

					if (a[enumId] < a[imax]) 
					{
						myswap(&a[enumId],&a[imax]);
						enumId = imax;
					} else
						break;
				}
				else
					break;					
			} while (true);
		}

		checkResult(a,n);
		sw.stopNprint("[Heap_imprv] end");
	}

private:

	int heap_child_left(int node, int n) 
	{
		int level = trunc( log10(node+1)/log10(2));			// level
		int index1 = (node + 1) - ((1 << level));			// zero base
		int index2 = (1 << (level+1)) + 2*index1 - 1;

		//printf("[%d].childleft = %d\r\n",node,index2);
		return index2 < n  ? index2 : -1;
	}

	int heap_child_right(int node, int n)
	{
		int level = trunc( log10(node+1)/log10(2));			// level
		int index1 = (node + 1) - ((1 << level));					// zero base
		int index2 = (1 << (level+1)) + 2*index1;

		//printf("[%d].childright = %d\r\n",node,index2);
		return index2 < n ? index2 : -1;
	}

	int heap_parent(int node, int n)
	{
		int level = trunc( log10(node+1)/log10(2));			// level
		int index1 = (node + 1) - ((1 << level));			// zero base
		int parent =  (level - 1>=0)
								? (1 << (level-1)) + trunc(index1/2) - 1
								: trunc(index1/2) - 1;

		//printf("[%d].parent = %d; level=%d\r\n",node,parent,level);
		return parent < n ? parent : -1;
	}

	int k_heap_parent(int node, int n, int degree) 
	{
		int level = trunc(log10(node+1)/log10(degree));			// level

		int index1 = (node + 1) - pow(degree,level);			// zero base
		int parent =  (level - 1>=0)
								? trunc(pow(degree,level-1)) + trunc(index1/2) - 1
								: trunc(index1/2) - 1;

		printf("[%d].parent=%d; [%d].level=%d\r\n", node, parent,node, level);

		return parent < n ? parent : -1;
	}

	bool k_heap_getchild(int node, int n, int degree,int childs[], int &countchild )
	{
		int level = trunc( log10(node+1)/log10(degree));			// level
		int index1 = (node + 1) - pow(degree,level);				// zero base
		int index2 = pow(degree, level+1) + 2*index1 - 1;
		int index3 = pow(degree, level + 2);

		countchild = themax(0, themin(n - index2, index3-index2));

		for (int j=0;j<countchild;j++)
			childs[j] = j + index2;

		printf("[%d].childs = ", node);
		for (int j=0;j<countchild;j++) {
			printf("%d,", childs[j]);
		}
		printf("\r\n");

		return countchild > 0;
	}

	void myswap(int *a, int *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	void printArray(int a[], int n)
	{
		for (int i=0;i<n-1;i++) {
			if (a[i] > a[i+1])
				printf("ERRRORRR\r\n");
		}

		for (int i=0;i<n;i++)
			printf("%d, ", a[i]);

		printf("\r\n");
	}

	void generateData(int *a, int n)
	{
		for (int i=0;i<n;i++)
			a[i] = rand();
	}

	void checkResult(int*a, int n)
	{
		for (int i=0;i<n-1;i++)
		{
			if (a[i] > a[i+1])
			{
				printf("ERROR!!!\r\n");
			}
		}
	}
};

Sort::Sort() : _pImp(new Impl()) {
}

Sort::~Sort() {
}

void Sort::Run()
{
	//_pImp->bubbleSort_topDown();
	//_pImp->bubbleSort_bottomUp();
	// _pImp->insertion();
    // _pImp->insertion_imprv();
	// _pImp->heap();
	_pImp->k_heap(3);	
}
