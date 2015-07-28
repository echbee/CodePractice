#include "../headers/MainHeader.h"

#include <ctype.h>

int isPalindrome(string A) {
	string s;

	for(int i=0;i<A.length();i++)
	{
		if(A[i] >= 65 && A[i] <=90)
		{
			s.push_back(tolower(A[i]));
		}
		else if((A[i] >= 97 && A[i] <=122) || A[i] >= 48 && A[i] <=57)
		{

			s.push_back(A[i]);
		}
		else
		{
			//DoNothing
		}
	}
	cout<< s <<endl;

	//check for pallindrome in s

	if(s.size()==0)
		return 1;

	for(int i=0;i<=(s.length()-1)/2;i++)
	{
		if(s[i]!=s[s.length()-1-i])
		{
			return 0;
		}
	}

	return 1;
}
