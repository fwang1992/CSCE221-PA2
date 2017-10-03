//============================================================================
// Name        : Input.cpp
// Author      : Fang Wang
// Date        : 02-13-2017
// Copyright   : 
// Description : Input generation
/*   Usage:
*			input.cpp file is used to generate input files for sorting. 
*			Modify size for different integer set sizes
*			It will produce 3 txt files with the name inputR.txt inputIn.txt inputDe.txt  
*			for random, increasing, decreasing data sets respectively.
*			These files are then used for sorting by specifying input file names to read in
*/ 
//============================================================================


#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;



void BubbleSort(int A[], int size)			// use bubblesort to get increase/decrease data set
{
  int n=size;
  int temp;
  bool swapped;
  do 
  {
  	swapped=false;
	for (int i=1;i<n;i++)
	{
		if  (A[i-1]>A[i])    // if true swap element values
		{
			temp=A[i-1];
			A[i-1]=A[i];
			A[i]=temp;
			swapped=true;
		}
	}
	n=n-1;                   // after iteration the last element is sorted
  }while(swapped); 
}

int main()
{
	ofstream outputFile;
	outputFile.open("inputR.txt");
	int size=100000;
	cout<<"Generating input file for random integers size of "<<size<<endl;                                 
	unsigned seed=time(0);                            //set seed 
	srand(seed);
	outputFile<<size<<endl;                            //input format:first line is the number of integers
	for (int i=0;i<size;i++)
	{
		outputFile<<rand()<<endl;                      //generate size of random numbers
	}
	outputFile.close();                                //write to file

	outputFile.open("inputIn.txt");
	cout<<"Generating input file for increasing integers size of "<<size<<endl;
	ifstream inputFile;
	inputFile.open("inputR.txt");
	inputFile>>size;
	int A[size];
	for (int i=0;i<size;i++) inputFile>>A[i];          //read an integer until whitespace
	BubbleSort(A,size);
	outputFile<<size<<endl;
	for (int i=0;i<size;i++) outputFile<<A[i]<<endl;          //generate integers in increasing order
	outputFile.close();	

	outputFile.open("inputDe.txt");
	cout<<"Generating input file for decreasing integers size of "<<size<<endl;
	outputFile<<size<<endl;
	for (int i=size-1;i>=0;i--) outputFile<<A[i]<<endl;       //generate integers in decreasing order
	outputFile.close();	

	return 0;
}