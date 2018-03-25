#include "../headers/MainHeader.h"
#include <iostream>

int findMin(const vector<int> &A)
{
	//cout<<"A.front = "<<A.front()<<endl;
	//cout<<"A.back = "<<A.back()<<endl;

	if(A.front() < A.back() || A.size())
		return A.front();

	typedef vector<int>::const_iterator c_iter;
	c_iter start = A.begin();
	c_iter end = A.end();

	c_iter result;

	while(true)
	{
		c_iter mid = start + (end - start)/2;

		//cout <<"start = "<<*start<<endl;
		//cout <<"end = "<<*end<<endl;
		//cout <<"mid = "<<*mid<<endl;
		if(*mid < *(mid-1) && (mid==(A.end()-1) || *mid < *(mid+1)))
		{
			result = mid;
			return A.at(result - A.begin());
		}

		if(*start < *mid)
		{
			start = mid;
		}
		else
		{
			end = mid;
		}
	}
}
