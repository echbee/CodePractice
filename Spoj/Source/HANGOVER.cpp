#include "../Headers/MainHeader.h"

#include <iostream>

using namespace std;

typedef long int llint;

void HANGOVER()
{
	float n;
	scanf("%f",&n);
	while(n!=0)
	{
		int i;
		float res = 0;
		for(i=1;res<n;i++)
		{
			res = res + 1.0/(i+1);
		}
		printf("%d card(s)\n",(i-1));
		scanf("%f",&n);
	}
}
