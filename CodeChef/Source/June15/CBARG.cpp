#include "../../Header/MainHeader.h"

#include<iostream>

using namespace std;

typedef long long int llint;

void CBARG()
{
	llint test;
	cin>>test;
	for(;test>0;test--)
	{
		llint n;
		cin>>n;

		llint result = 0;
		llint allocated = 0;
		llint val = 0;

		for(llint i=0;i<n;i++)
		{
			cin>>val;

			if(allocated<val)
			{
				result += (val-allocated);
			}

			allocated = val;
		}

		cout<<result<<endl;
	}
}
