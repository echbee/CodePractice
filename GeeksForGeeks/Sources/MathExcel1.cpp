/*
 * MathExcel1.cpp
 *
 *  Created on: Aug 21, 2015
 *      Author: labuser
 */

#include "../Headers/MainHeader.h"

int charToNum(char c)
{
	return (c-64);
}

int titleToNumber(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int ans = 0;
	for(int i=0;i<A.size();i++)
	{
		ans = ans * 26 + charToNum(A[i]);
	}

	return ans;

}
