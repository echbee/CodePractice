#include "../headers/MainHeader.h"

int searchMatrix(vector<vector<int> > &A, int B) {
    
    //find row which whose start is just greater than B
    
    typedef vector<int>::iterator iter;
    
    typedef vector<vector<int> >::iterator deepIter;
    
    deepIter start = A.begin();
    deepIter end = A.end();
    
    deepIter s_row;
    
    while(start<end)
    {
        deepIter mid = start + (end - start)/2;
        if((*mid)[0] >= B && (mid==A.begin() || (*(mid-1))[0] <= B))
        {
        	if((*mid)[0] == B)
        	{
        		s_row = mid;
        	}
        	else
            	s_row = mid-1;
            break;
        }
        else if((*mid)[0] > B)
        {
        	s_row = start;
            end = mid - 1;
        }
        else
        {
        	s_row = start;
            start = mid + 1;
        }
    }
    
    //apply binary search on s_row
    iter st = s_row->begin();
    iter ed = s_row->end();
    
    while(st<=ed)
    {
        iter md = st + (ed - st)/2;
        if(*md == B)
            return 1;
        else if(*md < B)
        {
            st = md + 1;
        }
        else
        {
            ed = md - 1;
        }
    }
    
    return 0;
    
}
