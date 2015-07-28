#include "../Headers/MainHeader.h"

#include <iostream>
#include <algorithm>

using namespace std;

void FASHION()
{
	int t;
	cin>>t;
	for(;t>0;t--)
	{
		int n;
		cin>>n;
		int *hotM = new int[n];
		int *hotF = new int[n];

		for(int i=0;i<n;i++)
			cin>>hotM[i];
		for(int i=0;i<n;i++)
			cin>>hotF[i];

		sort(hotM,hotM+n);
		sort(hotF,hotF+n);

		long long int ans = 0;
		for(int i=n-1;i>=0;i--)
			ans+= (hotM[i]*hotF[i]);
		cout<<ans<<endl;
		delete[] hotM,hotF;
	}
}
