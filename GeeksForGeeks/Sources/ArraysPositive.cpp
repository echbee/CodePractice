/*
 * ArraysPositive.cpp
 *
 *  Created on: Aug 21, 2015
 *      Author: labuser
 */

#include "../Headers/MainHeader.h"

#include <climits>

int firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	//scan 1;
	typedef vector<int>::iterator iter;
	for(iter i = A.begin();i<A.end();i++)
	{
		if(*i<=0)
		{
			*i = INT_MAX-2;
		}
	}

	//scan 2;
	for(iter i = A.begin();i<A.end();i++)
	{
		int index = *i>0 ? *i : -(*i); //taking mod
		if(index<=A.size())
		{
			if(A[index-1]<0) //value already found ... take care of same values
			{

			}
			else
			{
				A[index-1] = -A[index-1];
			}
		}
	}

	cout<<"Vector is "<<endl;
	for(iter i=A.begin();i!=A.end();i++)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
	//scan 3
	for(iter i=A.begin();i<A.end();i++)
	{
		if(*i > 0)
		{
			return i-A.begin();
		}
	}

	return A.size()+1;
}
