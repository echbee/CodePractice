/*
 * ANUUND.cpp
 *
 *  Created on: Jan 12, 2016
 *      Author: labuser
 */

#include "../../Header/MainHeader.h"

#include <iostream>
#include <algorithm>

using namespace std;

void ANUUND()
{
	int t;
	cin>>t;
	for(;t>0;t--)
	{
		long int n;
		cin>>n;
		long long int *arr = new long long int[n];


		for(long int i=0;i<n;i++)
			cin>>arr[i];

		sort(arr,arr+n);

		long long int t;
		for(long int i=1;i<n-1;i+=2)
		{
			//swap arr[i] and arr[i+1]
			t = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = t;
		}

		for(long int i=0;i<n;i++)
			cout<<arr[i]<<" ";

		cout<<endl;
		delete[] arr;
	}
}
