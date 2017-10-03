//============================================================================
// Name        : selection-sort.cpp
// Author      : Alejandra Sandoval
// Date        : Feb 15, 2017
// Copyright   : 
// Description : Implementation of selection sort in C++
//============================================================================

#include "sort.h"
#include <iostream>

void
SelectionSort::sort(int A[], int size)				// main entry point
{
	int n = size;
  /* Complete this function with the implementation of selection sort algorithm 
  Record number of comparisons in variable num_cmps of class Sort
  */
  for (int k = 0; k < n-1; k++)
	{
		int index = k;
		for (int i = k+1; i < n; i++){
			num_cmps++;
			if (A[i] < A[index]) index = i;
		}
		int tmp = A[k]; // swap A[k] and A[index]
		A[k] = A[index];
		A[index] = tmp;
	}

}
