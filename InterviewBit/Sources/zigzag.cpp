#include "../headers/MainHeader.h"

using namespace std;

string convert(string A, int B)
{
	string *result = new string[B];

	if(A.length()==0)
		return "";

	if(B==1)
		return A;

	typedef string::iterator iter;

	bool dirn = true;  //true = incr

	int index = 0;

	for(int i = 0;i<A.length();i++)
	{
		result[index] = result[index] + A.at(i);

		if(dirn)
				{
					index ++;
				}
				else
				{
					index--;
				}

				if(index == (B-1))
				{
					dirn = false;
				}
				else if(index == 0)
				{
					dirn = true;
				}
	}

	string ans;
	for(int i=0;i<B;i++)
	{
		cout<<result[i]<<endl;
		ans += result[i];
	}

	return ans;
}
