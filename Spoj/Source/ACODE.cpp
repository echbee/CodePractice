#include "../Headers/MainHeader.h"

#include <iostream>
#include <string>

using namespace std;

typedef long int llint;

void ACODE()
{
	string s;
	cin>>s;

	llint a0,a1,a2;
	while(s[0]!='0')
	{
		llint len = s.length();
		if(len==1)
		{
			cout<<"1"<<endl;
			cin>>s;
			continue;
		}
		a2 = (s[len-1]>='1' && s[len-1]<='9') ? 1 : 0;
		a1 = ((10*(s[len-2]-'0')+(s[len-1]-'0')<=26) && s[len-1]!='0') ? 2 : 1;
		if(s[len-2]=='0')
			a1 = 0;

		for(llint i=len-3;i>=0;i--)
		{
			a0 = ((s[i]!='0') ? a1 : 0) + ((10*(s[i]-'0') + (s[i+1]-'0') <= 26 && s[i]!='0') ? a2 : 0);
			a2 = a1;
			a1 = a0;
		}
		cout<<a1<<endl;
		cin>>s;
	}
}
