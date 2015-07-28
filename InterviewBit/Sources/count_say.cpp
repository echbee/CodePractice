#include "../headers/MainHeader.h"
#include <string>


using namespace std;

string calculate(string n)
{
	string ans = "";
	int index_first = 0,index_last;

	string p = n.substr(index_first,1);

	index_last = n.find_first_not_of(p,index_first);

	while(index_last != string::npos)
	{
		int count = index_last - index_first;
		ans += (to_string(count) + p);
		index_first = index_last;

		p = n.substr(index_first,1);

		index_last = n.find_first_not_of(p,index_first);
	}

	//for last case

	int count = n.length() - index_first;
	ans += (to_string(count) + p);

	return ans;
}

string countAndSay(int A)
{
	string s = "1";
	int num = 1;

	for(int i=1;i<A;i++)
	{
		s = calculate(s);
	}

	return s;
}
