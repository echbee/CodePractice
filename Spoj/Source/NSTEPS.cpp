#include "../Headers/MainHeader.h"
#include <iostream>

using namespace std;

void NSTEPS()
{
	int test;
	cin>>test;
	for(;test>0;test--)
	{
		int x,y;
		cin>>x>>y;
		int result;
		unsigned int step = 1;
		if(x==y)
		{
			result = 0;
			for(int i=1;i<=x;i++)
			{
				result = result + step;
				step = (step & 2) ? 1 : 3;
			}
			cout<<result<<endl;
		}
		else if((x-y)==2 && x>=2)
		{
			result = 2;
			for(int i=1;i<=(x-2);i++)
			{
				result = result + step;
				step = (step & 2) ? 1 : 3;
			}
			cout<<result<<endl;
		}
		else
		{
			cout<<"No Number"<<endl;
		}
	}
}
