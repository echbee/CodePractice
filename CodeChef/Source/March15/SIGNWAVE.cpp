#include "../../Header/MainHeader.h"

#include <cstdio>
#include<map>
#include<cmath>
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

string PIE = "PIE*";

void SIGNWAVE()
{
	int testCases;
	scanf("%d",&testCases);

	for(;testCases>0;testCases--)
	{
		int s,c,k;
		scanf("%d %d %d",&s,&c,&k);
		map<long double,int> table;
		long double start = 0;
		long double interval = 1;

		for(int i=0;i<s;i++)
		{
			interval=interval / pow(2,i);

			for(long double iter=start;iter<=2;iter+=interval)
			{
				//printf("iter = %lf\n",iter);


				if(table.find(iter)!=table.end())
				{
					table[iter] = table[iter]+1;
				}
				else
				{
					table.insert(pair<long double,int>(iter,1));
				}
			}
		}


		start = 1.0/2;
		interval = 1;

		for(int i=0;i<c;i++)
		{
			start= start / pow(2,i);
			interval= interval / pow(2,i);

			for(long double iter=start;iter<=2;iter+=interval)
			{
				if(table.find(iter)!=table.end())
				{
					table[iter]=table[iter]+1;
				}
				else
				{
					table.insert(pair<long double,int>(iter,1));
				}
			}
		}

		long long int result = 0;

		cout<<"Table size "<<table.size()<<endl;

		for(map<long double,int>::iterator iter = table.begin();iter!=table.end();iter++)
		{
			cout<<iter->first<<" "<<iter->second<<endl;
			if(iter->second>=k)
			{
				result++;
			}
		}

		printf("%lld\n",result);
	}
}
