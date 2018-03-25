/*
 * OJUMPS.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: labuser
 */

#include "../../Header/MainHeader.h"
#include <iostream>
#include <string>

using namespace std;

int calculateSum(int *arr,int size)
{
	int ans = 0;
	for(int i=0;i<size;i++)
		ans+=arr[i];
	return ans;
}

void subtractOne(int *arr,int size)
{
	if(arr[size-1]>=1)
	{
		arr[size-1]--;
		return;
	}
	else
	{
		int carryIndex;
		for(int i=size-1;i>=0;i--)
		{
			if(arr[i]==0)
				continue;
			else
			{
				carryIndex = i;
			}
		}

		arr[carryIndex]--;

		for(int i=carryIndex+1;i<size;i++)
		{
			if(arr[i] == 0)
				arr[i] = 9;
		}
	}
}

void OJUMPS()
{
	string s;
	cin>>s;
	int *arr = new int[s.size()];
	int i=0;
	for(string::iterator it = s.begin();it!=s.end();it++,i++)
	{
		arr[i] = *it - 48;
	}

	/*cout<<"arr is :";

	for(int i=0;i<s.size();i++)
		cout<<arr[i]<<" ";
*/
	if(s.size()==1 && (arr[0]==0 || arr[0]==1))
	{
		cout<<"yes";
		return;
	}

	//check if it is divisible by 3
		// calculate sum
		//check if sum is divisible by 3
	int sum = calculateSum(arr,s.size());
	if(sum%3 == 0)
	{
	//	cout<<"SumDivisible by 3"<<endl;
		cout<<"yes";
		return;
	}

	//if not... subtract 1 and check if it is divisible by 6

	subtractOne(arr,s.size());

	sum = calculateSum(arr,s.size());

	/*cout<<"After subtraction arr is :";

	for(int i=0;i<s.size();i++)
		cout<<arr[i]<<" ";
*/
	if(sum%3 == 0 && (arr[s.size()-1]%2) == 0)
	{
	//	cout<<"Sum divisible by 6"<<endl;
		cout<<"yes";
		return;
	}
	else
	{
		cout<<"no";
		return;
	}
	return;
}
