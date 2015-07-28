#include "../Headers/MainHeader.h"

#include <iostream>

using namespace std;

typedef long int llint;

void ACPC10A_APFirst()
{
	llint n1,n2,n3;
	cin>>n1>>n2>>n3;
	while(n1!=0 && n2!=0 && n3!=0)
	{
		//check for AP
		if((n2-n1)==(n3-n2))
		{
			cout<<"AP "<<(n3+(n3-n2));
		}
		else
		{
			cout<<"GP "<<n3*(n3/n2);
		}
		cout<<endl;
		cin>>n1>>n2>>n3;
	}
}

void ACPC10A()
{
	llint n1,n2,n3;
	cin>>n1>>n2>>n3;
	while(n1!=0 || n2!=0 || n3!=0)
	{
		//check for AP
		if((2*n2)==(n1+n3))
		{
			cout<<"AP "<<(n3+(n3-n2));
		}
		else if((n2*n2)==n1*n3)
		{
			if(n2!=0)
				cout<<"GP "<<(n3*(n3/n2));
			else
				cout<<"GP "<<(n3*(n2/n1));
		}
		cout<<endl;
		cin>>n1>>n2>>n3;
	}
}
