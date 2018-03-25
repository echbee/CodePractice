#include "../headers/MainHeader.h"

#include <limits.h>

int sqrt(int A)
{

	//find possible range
	long long int start,end;
	start = 1;
	end = 2;
	while(end*end < A)
	{
		start = end;
		end = end * end;
	}

	if((long long int)(start*start)==A)
		return start;
	if(((long long int)(end*end))==A)
		return end;

	//find value in [start,end]
	while(start<=end)
	{
		long long int mid = start + (end-start)/2;
		long long int midSq = mid*mid;
		long long midSq_1 = midSq+2*mid+1;
		if(midSq==A || (midSq_1 > A && midSq< A))
			return mid;
		else if(midSq < A)
		{
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}
	}
}
