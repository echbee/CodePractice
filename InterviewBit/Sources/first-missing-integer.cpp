/*
 * ArraysPositive.cpp
 *
 *  Created on: Aug 21, 2015
 *      Author: labuser
 */

#include <climits>
#include "MainHeader.h"

int firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    bool *arr = new bool [A.size()];
    
    for(int i=0;i<A.size();i++)
        arr[i] = false;
    
    for(auto &x : A)
    {
        if(x>0 && x<=A.size())
        {
            arr[x-1] = true;
        }
    }
    
    int resultIndex = A.size();
    for(int i=0;i<A.size();i++)
    {
        if(arr[i] == false)
        {
            resultIndex = i;
            break;
        }
    }
    
    if(resultIndex == A.size())
        return A.size()+1;
    else
        return resultIndex+1;
    
}
