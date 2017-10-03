//============================================================================
// Name        : radix-sort.cpp
// Author      : Abraham Hinojosa
// Date        : 2/17/2017
// Copyright   : 
// Description : Implementation of radix sort in C++
//============================================================================
#include "sort.h"
#include <iostream>
using namespace std;

// counting sort will be called by radix sort to sort digits not only by
// value but by what instance of a digit came first
void countSort(int a[], int sz, int exp){
	int map[sz];
	int count[10] = {0,0,0,0,0,0,0,0,0,0}; // digits only range from 0-9 
	
	// store number of occurences of a digit
	for(int i=0; i<sz;i++){
		count[(a[i]/exp)%10]++;
	}
	// 
	for(int i=1; i<10;i++){
		// adding current and previous 
		count[i] += count[i-1];
	}
	// Build map...
	for(int i=sz-1; i >= 0; i--){
		map[count[(a[i]/exp)%10] -1] = a[i];
		count[(a[i]/exp)%10]--;
	}
	// Updateing original array based on map
	for(int i=0; i<sz;i++) a[i] = map[i];
}
// used to know if their is a negative number in the unsorted array 
int fetchMin(int a[],int n){
	int smallest = a[0]; // default set to smallest element
	// loop walks trough array compares smallest digit
	// to digit in array if digit is smaller it sets it as
	// as smallest in array
	for(int number = 1; number < n ;number ++){
		if(smallest > a[number]) smallest = a[number];
	}
	return smallest;
}
// used to find largetst number in array to know how
// many digits it has so we can know how many times 
// counting sort will be operated
int fetchMax(int a[], int n){
	int biggest = a[0]; // default set to first element in array
	
	// loop walks trough array compares biggest digit
	// to digit in array if digit is bigger it sets it as
	// as biggest in array
	for(int number = 1; number < n ;number ++){
		if(biggest < a[number]) biggest = a[number];
	}
	return biggest;
}



 //radix sort to sort number array uses counting sort
void RadixSort::sort(int a[], int sz){
	int numcmps =0;
	// find biggest number
	int big = fetchMax(a,sz);
	// find smallest number
	int small = fetchMin(a,sz);
	// takeing negative into account
	if(small < 0){
		for(int i=0;i<sz;i++){
			a[i]= a[i] + small;
		}
	}
	//Radix applys counting sort to each digit 
	for(int exp =1; big/exp > 0; exp = exp*10){
		countSort(a,sz,exp);
	}
	// undos the process done to take negatives into 
	//account 
	if(small < 0){
		for(int i=0;i<sz;i++){
			a[i]= a[i] - small;
		}
	}
}

