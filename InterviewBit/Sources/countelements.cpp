
#include <vector>
#include <iostream>

using namespace std;

int findFirst(const vector<int> &A,int B)
{
	vector<int>::const_iterator first = A.begin();
	vector<int>::const_iterator last = A.end();


	vector<int>::const_iterator start = first;
	vector<int>::const_iterator end = last;


	while(start<end)
	{
		vector<int>::const_iterator mid = start + (end-start)/2;
		cout<<"Start ="<<(start-first)<<endl;
		cout<<"End ="<<(end-first)<<endl;
		cout<<"Mid ="<<(mid-first)<<endl;


		if((*mid) == B && ( mid == first || (*(mid-1))!=B ) )
		{
			return mid - first;
		}
		else if(*mid < B)
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}

	return -1;

}


int findLast(const vector<int> &A,int B)
{
	vector<int>::const_iterator first = A.begin();
	vector<int>::const_iterator last = A.end();


	vector<int>::const_iterator start = first;
	vector<int>::const_iterator end = last;


	while(start<end)
	{
		vector<int>::const_iterator mid = start + (end-start)/2;

		if((*mid) == B && ( mid == (last-1) || (*(mid+1))!=B ) )
		{
			return mid - first;
		}
		else if(*mid > B)
		{
			end = mid;
		}
		else
		{
			start = mid + 1;
		}
	}

	return -1;

}

int findCount(const vector<int> &A, int B) {
	int firstOccur = findFirst(A,B);

	if(firstOccur == -1)
		return 0;

	int lastOccur = findLast(A,B);

	return (lastOccur - firstOccur + 1);

}
