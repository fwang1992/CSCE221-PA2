//============================================================================
// Name        : bubble-sort.cpp
// Author      : Fang Wang
// Date        : 02-08-2017
// Copyright   : 
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"

void 
BubbleSort::sort(int A[], int size)			// main entry point
{
  /* Complete this function with the implementation of bubble sort algorithm 
     Record number of comparisons in variable num_cmps of class Sort
  */
  int n=size;
  int temp;
  bool swapped;
  do 
  {
  	swapped=false;
	for (int i=1;i<n;i++)
	{
		if  (num_cmps++,A[i-1]>A[i])    // if true swap element values
		{
			temp=A[i-1];
			A[i-1]=A[i];
			A[i]=temp;
			swapped=true;
		}
	//	num_cmps++;          // keep trakc of number of comparisons 
	}
	n=n-1;                   // after iteration the last element is sorted
  }while(swapped);
  
}

