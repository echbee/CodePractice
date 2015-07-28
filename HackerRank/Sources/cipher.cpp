#include "../Headers//MainHeader.h"
#include<iostream>
#include<string>

using namespace std;

typedef long long int llint;

enum state {inc_st,const_st,dec_st};

void cipher()
{
	llint n,k;
	cin>>n>>k;
	string arr;
	cin>>arr;
	llint s = arr.length();

	llint inc_ct = k-1;
	llint const_ct = s-k;
	state stt = inc_st;

	if(k==1)
	{
		cout<<arr<<endl;
		return;
	}

	short *output = new short[n];
	output[0] = arr[0]-48;

	for(int i=1;i<n;i++)
	{
		switch(stt)
		{
		case inc_st:
			output[i] = (arr[i]-48) ^ (arr[i-1]-48);
			if(i==inc_ct)
				stt = const_st;
			break;
		case const_st:
			output[i] = (arr[i]-48) ^ (arr[i-1]-48) ^ (output[i-k]);
			if(i==const_ct)
				stt = dec_st;
			break;
		case dec_st:
			output[i] = arr[s-1];
			break;
		}
	}
	for(int j=0;j<n;j++)
		cout<<output[j];
	cout<<endl;

	delete[] output;
}
