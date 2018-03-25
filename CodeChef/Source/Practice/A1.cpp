/*
 * A1.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: labuser
 */

#include "../../Header/MainHeader.h"
#include <iostream>

#include <algorithm>

#include <map>

using namespace std;


bool isPossible(long int n,long int m,int *arr,map<int,bool> &mapper, bool *isUsed)
{
	if(m==0)
	{
		mapper[0] = true;
		return true;
	}
	if(mapper.find(m) != mapper.end())
	{
		return mapper[m];
	}

	for(long int i=0;i<n;i++)
	{
		if(isUsed[i]==false && arr[i]<=m)
		{
			isUsed[i] = true;
			bool ans = isPossible(n,m-arr[i],arr,mapper,isUsed);
			isUsed[i] = false;
			if(ans == true)
			{
				mapper[m] = true;
				return true;
			}
			else
			{
				continue;
			}
		}
	}

	mapper[m] = false;
	return false;
}

void A1()
{
	int t;
	cin>>t;
	for(;t>0;t--)
	{
		long int n,m;
		cin>>n>>m;
		int *arr = new int [n];

		bool *isUsed = new bool [n];

		if(m>20000)
		{
			cout<<"No"<<endl;
			return;
		}

		for(long int i=0;i<n;i++)
		{
			cin>>arr[i];
			isUsed[i] = false;
		}

		map<int,bool> mapper;


		bool ans = isPossible(n,m,arr,mapper,isUsed);

		cout<<(ans==true ? "Yes" : "No")<<endl;

	}
}
