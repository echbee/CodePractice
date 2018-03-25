/*
 * ANUBTG.CPP
 *
 *  Created on: Jan 12, 2016
 *      Author: labuser
 */

#include "../../Header/MainHeader.h"

#include <iostream>
#include <algorithm>

using namespace std;

void ANUBTG()
{
	int t;
	cin>>t;
	for(;t>0;t--)
	{
		int n;
		cin>>n;
		int *arr = new int [n];


		for(int i=0;i<n;i++)
			cin>>arr[i];

		long int price = 0;

		sort(arr,arr+n);

		int index;
		for(index=n-1;index>=3;index-=4)
		{
			price += (arr[index] + arr[index-1]);
		}

		if(index==2)
			price += (arr[index] + arr[index-1]);
		else if(index == 1 || index == 0)
		{
			while(index>=0)
			{
				price += arr[index];
				index--;
			}
		}
		else
		{
			// do nothing... found multiple of 4
		}

		cout<<price<<endl;
		delete[] arr;
	}
}
