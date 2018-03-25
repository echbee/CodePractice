#include "../Headers/MainHeader.h"

#include <cstdio>

void KAMIL()
{
	int c;
	for(int t=10;t>0;t--)
	{
		long a=1;
		while((c = getchar())!='\n')
		{
			switch(c)
			{
			case 84:
			case 68:
			case 76:
			case 70:
			a*=2;
			}
		}
		printf("%ld\n",a);
	}
}
