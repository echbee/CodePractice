#include "../headers/MainHeader.h"

int searchMin(const vector<int> &A)
{
	//cout<<"A.front = "<<A.front()<<endl;
	//cout<<"A.back = "<<A.back()<<endl;

	if(A.front() < A.back() || A.size()==1)
		return 0;

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
			return result - A.begin();
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


int searchIn(const vector<int> &A, int B) {
	int pivot = searchMin(A);

	int len = A.size();

	int start = pivot;
	int end = (pivot + len - 1);

	while(start<=end)
	{
		int mid = (start + (end - start)/2);
		int mid_mod = mid%len;

		if(A.at(mid_mod)==B)
			return mid_mod;
		else if(A.at(mid_mod) > B)
		{
			end = mid - 1;
		}
		else
		{
			start = (mid + 1);
		}

	}

	return -1;
}
