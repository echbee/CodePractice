#include "../headers/MainHeader.h"
#include <vector>

//using namespace std;

vector<int> spiral1(vector<vector<int> > &a)
{
		int m = a.size();
		int n = a[0].size();

		vector<int> ans;
		int s_row = 0,s_col = 0, e_row = m-1,e_col = n-1;

		while(s_row<=e_row && s_col<=e_col)
		{
		    bool singleRow=false,singleColumn=false;

		    if(s_row==e_row)
		        singleRow=true;
		    if(s_col==e_col)
		        singleColumn=true;

		    //print upper part
		    for(int i=s_col;i<=e_col;i++)
		    {
		        ans.push_back(a[s_row][i]);
		    }

		    for(int i=s_row+1;i<=e_row;i++)
		    {
		        ans.push_back(a[i][e_col]);
		    }

		    if(!singleRow)
		    {
	    	    for(int i=e_col-1;i>=s_col;i--)
	    	    {
	    	        ans.push_back(a[e_row][i]);
	    	    }
		    }

		    if(!singleColumn)
		    {
	    	    for(int i=e_row-1;i>=s_row+1;i--)
	    	    {
	    	        ans.push_back(a[i][s_col]);
	    	    }
		    }

		    //update rows and column indices
		    s_row+=1;
		    s_col+=1;
		    e_row-=1;
		    e_col-=1;

		}
	return ans;

}


vector<vector<int> > generate(int A) {

    vector<vector<int> > result;

    if(A==0)
    return result;

    vector<int> row0;
    row0.push_back(1);
    result.push_back(row0);

    vector<int> *prevRow = &row0;

    for(int i=2;i<=A;i++)
    {
        vector<int> *row = new vector<int>;
        for(int p=0;p<i;p++)
        {
            int sum = ((p<=(prevRow->size()-1)) ? prevRow->at(p) : 0 ) + ((p-1>=0) ? prevRow->at(p-1) : 0);
            row->push_back(sum);
        }
        prevRow = row;
        result.push_back(*row);
    }

    return result;
}


#include <math.h>

using namespace std;

vector<int> allFactors(int n) {

    vector<int> result;
    result.push_back(1);
    result.push_back(n);

    for(int i=2;i<=sqrt(n);i++)
    {
        if((n%i)==0)
        {
            int size = result.size();
            result.insert(result.begin()+size,i);
            if(i!=sqrt(n))
            {
                result.insert(result.begin()+size+1,n/i);
            }
        }
    }


    return result;
}


