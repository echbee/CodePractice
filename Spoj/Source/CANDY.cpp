#include "../Headers/MainHeader.h"

#include <iostream>

using namespace std;

void CANDY()
{
	int num;
	cin>>num;
	long long int sum;
	while(num!=-1)
	{
		sum = 0;
		int *arr = new int[num];
		for(int i =0;i<num;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		if((sum%num)!=0)
		{
			cout<<-1<<endl;
		}
		else
		{
			long long int val = sum/num;
			long long int ans = 0;
			for(int i=0;i<num;i++)
			{
				ans = ans + ((val-arr[i])>0 ? (val-arr[i]) : -(val-arr[i]));
			}
			cout<<ans/2<<endl;
		}
		delete[] arr;
		cin>>num;
	}
}
