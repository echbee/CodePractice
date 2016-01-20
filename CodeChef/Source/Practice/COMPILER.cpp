/*
 * COMPILER.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: labuser
 */

#include "../../Header/MainHeader.h"

#include <iostream>
#include <stdio.h>

using namespace std;

void COMPILER()
{
	int t;
	scanf("%d",&t);
	getchar();
	for(;t>0;t--)
	{
		unsigned long long int ans=0,counter=0;
		unsigned long long int index = 1;
		int c = getchar();
		while(c!= ' ' && c!= '\n' && c!= '\0' && c!= EOF)
		{
			//cout<<"C is "<<(char)c<<endl;
			if(c == '<')
			{
				counter++;
			}
			else
			{
				if(counter==0)
				{
					while(c!= ' ' && c!= '\n' && c!= '\0' && c!= EOF)
						c = getchar();
					break;
				}
				counter--;
				if(counter==0)
					ans = index;
			}

			index++;
			c = getchar();
			//cout<<"Next c is "<<(char)c<<endl;
		}
		cout<<ans<<endl;
	}
}
