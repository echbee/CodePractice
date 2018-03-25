/*
 * prog17.cpp
 *
 *  Created on: Aug 11, 2015
 *      Author: labuser
 */


#include "../Headers/MainHeader.h"
#include <string>

using namespace std;

void permute(string s,int index)
{
	if(index==s.length())
	{
		cout<<s<<endl;
		return;
	}
	else
	{
		//swap index with index+1 till length()-1
		for(int i=index;i<s.length();i++)
		{
			char c = s[index];
			s[index] = s[i];
			s[i] = c;

			permute(s,index+1);

			c = s[index];
			s[index] = s[i];
			s[i] = c;
		}
	}

}
