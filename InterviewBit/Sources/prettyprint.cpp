#include <vector>
#include<stdio.h>

using namespace std;

vector<vector<int> > prettyPrint(int A) {

    int size = 2*A-1;
    vector<vector<int> > arr;
    for(int i=0;i<size;i++)
    {
        vector<int> *v = new vector<int>(size);
        arr.push_back(*v);
    }

    int r_start=0,r_end=size-1,c_start=0,c_end=size-1;

    int s = arr.size();

    for(int v = A;v>=1;v--)
    {
    	if(v==1)
    	{
    		arr.at(r_start).at(c_start) = v;
    		break;
    	}

    	for(int i=c_start;i<=c_end;i++)
    	{
    		arr.at(r_start).at(i) = v;
    	}

    	for(int i=r_start+1;i<=r_end;i++)
    	{
    		arr.at(i).at(c_end) = v;
    	}

    	for(int i=c_end-1;i>=c_start;i--)
    	{
    		arr.at(r_end).at(i) = v;
    	}

    	for(int i=r_end-1;i>=r_start;i--)
    	{
    		arr.at(i).at(c_start) = v;
    	}

    	r_start+=1;
    	r_end-=1;
    	c_start+=1;
    	c_end-=1;
    	//spirally fill vector
    }

    return arr;
}
