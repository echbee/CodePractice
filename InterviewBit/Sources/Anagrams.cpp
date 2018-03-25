/*
 * Anagrams.cpp
 *
 *  Created on: Dec 16, 2015
 *      Author: labuser
 */

#include "../headers/MainHeader.h"

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector<int> > anagrams(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	multimap<string,int> multiMap;

	for(vector<string>::const_iterator i = A.begin();i!=A.end();i++)
	{
		string s(*i);
		sort(s.begin(),s.end());
		pair<string,int> p;
		p.first = s;
		p.second = (int)(i-A.begin()+1);
		multiMap.insert(p);
	}

	vector<vector<int> > ans;

	string temp = "";
	vector<int> *v = NULL;

	for(multimap<string,int>::iterator i = multiMap.begin();i!=multiMap.end();i++)
	{
		if(i->first == temp)
		{
			v->push_back(i->second);
		}
		else
		{
			temp = i->first;
			if(v!=NULL)
				ans.push_back(*v);
			v = new vector<int>();
			v->push_back(i->second);
		}
	}
	if(v != NULL)
	{
		ans.push_back(*v);
	}

	return ans;
}
