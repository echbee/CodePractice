#include "../headers/MainHeader.h"

#include <string>
#include <limits.h>

using namespace std;

int Myatoi(const string &A)
{

	int startingIndex = A.find_first_of("+-0123456789");

	for(int i=0;i<startingIndex;i++)
	{
		if(A.at(i)!=' ')
		{
			//garbage found...
			return 0;
		}
	}

	if(startingIndex == string::npos)
		return 0;

	bool isNegative = (A.at(startingIndex)=='-') ? true : false;

	if(A.at(startingIndex)=='+' || A.at(startingIndex)=='-')
		startingIndex++;

	long long int num = 0;

	for(int i=startingIndex;i<A.length();i++)
	{
		if(A.at(i)>=48 && A.at(i)<=57)
		{
			num = (long long int)(num*10) + (int)(A.at(i)) - 48 ;
			if(num > INT_MAX)
				break;
		}
		else
		{
			break;
		}
	}

	if(num > INT_MAX)
	{
		return isNegative ? INT_MIN : INT_MAX;
	}
	else
	{
		return isNegative ? (int)(-num): (int)(num);
	}

}
