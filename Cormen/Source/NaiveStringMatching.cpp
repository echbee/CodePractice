#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool AllStringCharDifferent(string s)
{
	sort(s.begin(),s.end());

	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i] ==s[i+1])
			return false;
	}
	return true;
}

void naiveStringMatching(string &text, string &pattern)
{

	bool optimizeAlgo = false;

	if(text.length()<pattern.length())
	{
		cout<<"Dumb Fuck!!";
		return;
	}

	if(AllStringCharDifferent(pattern))
	{
		cout<<"Cool, optimizing algo!!\n";
		optimizeAlgo = true;
	}

	int textLen = text.length();
	int patLen = pattern.length();
	int j,increment=1;
	for(int i=0;i<=(textLen-patLen);i+=increment)
	{
		for(j=0;j<patLen;j++)
		{
			if(text[i+j]==pattern[j])
				continue;
			else
			{
				increment = optimizeAlgo? (j+1) : 1;
				break;
			}
		}

		if(j==patLen)
		{
			increment = optimizeAlgo? (patLen+1) : 1;
			cout<<"Matching found at index:"<<i<<endl;
		}
	}
}
