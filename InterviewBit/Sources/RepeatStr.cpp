/*
 * RepeatStr.cpp
 *
 *  Created on: Dec 17, 2015
 *      Author: labuser
 */

#include "../headers/MainHeader.h"

#include <map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.length()==1)
		return 1;

	int ans = 1;
	int curLen = 1;

	map<char,int> dataStore;
	dataStore[A[0]] = 0;

	for(int i=1;i<A.length();i++)
	{
		map<char,int>::iterator t = dataStore.find(A[i]);
		if(t == dataStore.end() || t->second < (i-curLen))
		{//char not present in current subsequence
			curLen++;
		}
		else
		{// repeating char found
			cout<<"Repeating Char found at index "<<i<<endl;
			cout<<"Changing curLen to "<<i-t->second<<endl;
			if(ans<curLen)
			{
				cout<<"Current answer updated at index "<<i<<endl;
				ans = curLen;
			}
			curLen = i - t->second;
		}

		dataStore[A[i]] = i;
	}

	return ans;
}
