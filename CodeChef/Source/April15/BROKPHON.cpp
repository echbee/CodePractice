#include "../../Header/MainHeader.h"

#include <iostream>
#include <stdio.h>

void BROKPHON()
{
	int test;
	scanf("%d",&test);

	for(;test>0;test--)
	{
		long long int n;
		scanf("%lld",&n);
		long long int *arr = new long long int [n];
		for(long long int i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}

		long long int ans = 0;
		short change = 0;

		long long int current = arr[0];

		for(long long int i=1;i<n;i++)
		{
			if(arr[i] == current)
			{
				change = 0;
			}
			else
			{
				ans = ans + ((change==0) ? 2 : 1);
				change = 1;
				current = arr[i];
			}
		}

		printf("%lld\n",ans);
	}

}
