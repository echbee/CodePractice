#include "../Header/MainHeader.h"

#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

bool checkIfSubstring(string pattern, int k, int q, char c)
{
	if(pattern[k-1]!=c)
		return false;

	for(int i=0;i<=(k-2);i++)
	{
		if(pattern[k-2-i]!=pattern[q-i])
			return false;
	}
	return true;

}

void preProcess(string pattern,int **transitionFn,int sigmaLen)
{
	int k=0;
	char c;
	for(int i=0;i<pattern.length()+1;i++)
	{
		for(int j=0;j<sigmaLen;j++)
		{
			c = 'a'+j;
			k = (i+1>pattern.length() ) ? (i+1) : pattern.length();
			while(k>=0)
			{
				if(checkIfSubstring(pattern,k,i,c))
				{
					transitionFn[i][j] = k;
					break;
				}
				k--;
			}
		}
	}
}

void RabinKarpMatching(string pattern,string text) //assuming sigma is a,b,c
{
	const int sigmaLen = 3;
	int **transitionFn = new int*[pattern.length()+1];
	for(int i=0;i<pattern.length()+1;i++)
	{
		transitionFn[i] = new int[sigmaLen];
	}

	preProcess(pattern,transitionFn,sigmaLen);

	for(int i=0;i<pattern.length()+1;i++)
	{
		for(int j=0;j<sigmaLen;j++)
		{
			cout<<transitionFn[i][j]<<" ";
		}
		cout<<endl;
	}
}
