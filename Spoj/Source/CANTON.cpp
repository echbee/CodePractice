#include "../Headers/MainHeader.h"

#include <iostream>
#include <cmath>

using namespace std;

typedef long int llint;

void CANTON()
{
	short t;
	cin>>t;
	for(;t>0;t--)
	{
		llint num;
		cin>>num;

		long double val =((sqrt(8*num+1)-1)/2);
		llint val_int = (llint)val;


		bool flag = ((val_int%2)==0) ? false : true; //false = down... true = up

		if((val-val_int)==0)
		{
			if(flag)
			{
				cout<<"TERM "<<num<<" IS "<<"1/"<<val_int<<endl;
			}
			else
			{
				cout<<"TERM "<<num<<" IS "<<val_int<<"/1"<<endl;
			}
			continue;
		}

		flag = (((val_int+1)%2)==0) ? false : true; //false = down... true = up


		llint sum = (val_int*(val_int+1))/2;

		llint diff = num-sum;

		llint numerator,denominator;

		if(flag) // up
		{
			denominator = diff;
			numerator = (val_int+1) - (diff-1);
		}
		else //down
		{
			numerator = diff;
			denominator = (val_int+1) - (diff-1);
		}

		cout<<"TERM "<<num<<" IS "<<numerator<<"/"<<denominator<<endl;
	}
}
