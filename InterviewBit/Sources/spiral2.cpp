/*
 * spiral2.cpp
 *
 *  Created on: Dec 18, 2015
 *      Author: labuser
 */

#include "../headers/MainHeader.h"

#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > ans(A,vector<int>(A));

    int value = 1;
    for(int i=0;i<(A+1)/2 ; i++)
    {
    	for(int j=i;j<=A-1-i;j++)
    	{
    		ans[i][j] = value;
    		value++;
    	}

    	for(int j=i+1;j<=A-1-i;j++)
    	{
    		ans[j][A-1-i] = value;
    	    value++;
    	}

    	for(int j=A-1-i-1;j>=i;j--)
    	{
    		ans[A-1-i][j] = value;
    	    value++;
    	}

    	for(int j=A-1-i-1;j>i;j--)
    	{
    		ans[j][i] = value;
    	    value++;
    	}
    }

    return ans;
}
