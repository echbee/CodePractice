//need to enable -std = c++11 flag in compiler

#include "../Headers/MainHeader.h"

#include <iostream>
#include <cstdint>

using namespace std;

void flipping_bits()
{
	short int t;
	cin>>t;
	for(;t>0;t--)
	{
		uint32_t num;
		cin>>num;
		uint32_t n = ~(0);
		cout<<(num ^ n)<<endl;
	}
	return;
}
