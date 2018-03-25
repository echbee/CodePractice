#include "../Headers/MainHeader.h"

#include <iostream>
#include <cstdio>

using namespace std;

#include <unordered_map>

typedef long int llint;

unordered_map<long long int ,long long int> hashtable;

long long int maximum(long long int& a, long long int& b)
{
	return a>b ? a : b;
}

long long int MaxValue(long long int n)
{
	unordered_map<long long int,long long int>::const_iterator it = hashtable.find(n);

	if(it==hashtable.end())
	{
		long long int t = MaxValue(n/2)+MaxValue(n/3)+MaxValue(n/4);
		long long int val = maximum(n,t);
		hashtable[n] = val;
		return val;
	}
	else
	{
		return it->second;
	}

}

void COINS()
{
	hashtable[0] = 0;
	hashtable[1] = 1;
	hashtable[2] = 2;
	long long int n;
	while(cin>>n)
	{
		cout<<MaxValue(n)<<endl;
	}
}
