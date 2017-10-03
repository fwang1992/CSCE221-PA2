//============================================================================
// Name        : insertion-sort.cpp
// Author      : Alejandra Sandoval 
// Date        : February 15, 2107
// Copyright   : 
// Description : Implementation of insertion sort in C++
//============================================================================

#include "sort.h"

void
InsertionSort::sort(int A[], int size)				// main entry point
{
  /* Complete this function with the implementation of insertion sort algorithm 
  Record number of comparisons in variable num_cmps of class Sort
  */
	int n = size;
	
	for (int k = 1; k < n; k++ )
	{
		int tmp = A[k];
		int j = k;
		for( ; j > 0 && (num_cmps++,tmp < A[j-1]) ; j--){
			A[j] = A[j-1];
		}
		A[j] = tmp;
	}

}
