#include "../Headers/MainHeader.h"
#include <iostream>

using namespace std;

typedef long long int llint;

void SAMER08F()
{
	int num;
	cin>>num;
	while(num!=0)
	{
		llint ans;
		ans = (num*(num+1)*(2*num+1))/6;
		cout<<ans<<endl;
		cin>>num;
	}
}
