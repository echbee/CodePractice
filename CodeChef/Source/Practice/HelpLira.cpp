/*
 * HelpLira.cpp
 *
 *  Created on: Jan 19, 2016
 *      Author: labuser
 */

#include "../../Header/MainHeader.h"

#include <iostream>
#include<climits>

using namespace std;

void HelpLira()
{
	int n;
	cin>>n;
	long int small = INT_MAX;
	long int large = INT_MIN;
	int smallIndex,largeIndex;
	for(int t=1;t<=n;t++)
	{
		int coord[6];
		for(int i=0;i<6;i++)
			cin>>coord[i];

		long long int mult = coord[0]*coord[3] + coord[2]*coord[5] + coord[4]*coord[1] - coord[2]*coord[1] - coord[4]*coord[3] - coord[0]*coord[5];
		mult = mult>=0 ? mult : -mult;
		long int ans = mult/2;

		if(ans<small)
		{
			small = ans;
			smallIndex = t;
		}
		if(ans>large)
		{
			large = ans;
			largeIndex = t;
		}
	}

	cout<<smallIndex<<" "<<largeIndex;
}
