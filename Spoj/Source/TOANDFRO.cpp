#include "../Headers/MainHeader.h"
#include <iostream>

using namespace std;

typedef long long int llint;

void TOANDFRO()
{
	int inc1,inc2,len;
	bool flag;
	int index;

	short col;
	cin>>col;

	while(col)
	{
		flag = true;
		inc1 = 2*col-1;
		inc2 = 1;

		string s;
		cin>>s;
		len = s.length()/col;
		for(int i=0;i<col;i++)
		{
			index = i;
			for(int j=0;j<len;j++)
			{
				cout<<s[index];
				if(flag)
				{
					index = index + inc1;
					flag = false;
				}
				else
				{
					index = index + inc2;
					flag = true;
				}
			}
			inc1 -=2;
			inc2 +=2;
			flag = true;
		}
		cout<<endl;
		cin>>col;
	}
}
