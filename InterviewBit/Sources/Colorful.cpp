/*
 * Colorful.cpp
 *
 *  Created on: Dec 16, 2015
 *      Author: labuser
 */


#include "../headers/MainHeader.h"

#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

int findLen(int a)
{
	if(a==0)
		return 1;

	int count = 0;
	while(a!=0)
	{
		count++;
		a/=10;
	}

	return count;
}

int colorful(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int numLen = findLen(A);

	map<int,bool> hashMap;

	int *arr = new int[numLen];
	for(int i=0;i<numLen;i++)
		arr[i] = 1;


	string numStr = to_string(A);
	for(int l=1;l<=numLen;l++)
	{
		for(int i=0;i<=numLen-l;i++)
		{

			arr[i] = arr[i] * ((int)numStr.at((i+l-1)) - 48);

			/*cout<<"For i="<<i<<" and l="<<l<<endl;
			for(int p=0;p<numLen;p++)
				cout<<arr[p]<<" ";
			cout<<endl;
			*/
			if(hashMap.find(arr[i]) == hashMap.end())
			{ //value not found
				hashMap[arr[i]] = true;
			}
			else
			{//value found
				return 0;
			}
			//now i points to the starting index of the subsequence
		}
	}

	return 1;
}
