#include <algorithm>

using namespace std;

bool cmp(int n1,int n2)
{
    if(n1==0)
        return true;
    if(n2==0)
        return false;

    int n1len=0,n2len=0;

    int t1=n1,t2=n2;

    int n1Arr[100],n2Arr[100];

    while(t1!=0)
    {
        n1Arr[n1len++] = t1%10;
        t1/=10;
    }

    while(t2!=0)
    {
        n2Arr[n2len++] = t2%10;
        t2/=10;
    }

    if(n1len==n2len)
    {
        if(n1<=n2)
            return true;
        else
            return false;
    }
    else
    {
        int maxLen = n1len>n2len ? n1len : n2len;

        int count,index1=0,index2=0,temp1,temp2;

        bool n1Over = false,n2Over = false;

        for(count=0;count<maxLen;count++) //n1<n2
        {
            index1 = n1len-1-count;
            index2 = n2len-1-count;

            if(index1>=0)
            {
            	temp1 = n1Arr[index1];
            }
            else
            {
            	n1Over = true;
            	temp1 = 0;
            }

            if(index2>=0)
            {
            	temp2 = n2Arr[index2];
            }
            else
            {
            	n2Over = true;
            	temp2 = 0;
            }

            if(temp1<temp2)
            {
                continue;
            }
            else if(temp1==temp2)
            {
            	if(n1Over)
            	{
            		return false;
            	}
            	if(n2Over)
            	{
            		return true;
            	}
            	continue; //else condition
            }
            else
            {
                return false;
            }

        }

        return true;
    }
}

string largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans(A);
    sort(ans.begin(),ans.end(),cmp);
    string s;

    for(int i=0;i<ans.size();i++)
    {
    	s+=ans[i];
    }

    return s;

}
