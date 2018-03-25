#include "../../Header/MainHeader.h"

#include<cstdio>

using namespace std;

void CNOTE()
{
	long long int testCases;
	scanf("%lld",&testCases);

	for(;testCases>0;testCases--)
	{
		bool result = false;
		int x,y,k;
		long long int n;
		scanf("%d %d %d %lld",&x,&y,&k,&n);

		int pagesNeeded = x-y;

		for(long long int i=0;i<n;i++)
		{
			int numPages,cost;
			scanf("%d %d",&numPages,&cost);
			if(!result)
			{
				if(cost<=k && numPages>=pagesNeeded)
				{
					result = true;
				}
			}
		}
		if(result)
		{
			printf("LuckyChef\n");
		}
		else
		{
			printf("UnluckyChef\n");
		}
	}
}
