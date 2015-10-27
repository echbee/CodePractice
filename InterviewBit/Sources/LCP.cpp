#include "../headers/MainHeader.h"

using namespace std;

void print(int n,bool *arr,int len)
{
	cout<<"table no:"<<n<<"\t";

	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

string longestPalindrome(string s) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = s.length();

    if(n==0)
        return s;
    if(n==1)
        return s;

    bool **table = new bool*[3];

    for(int i=0;i<3;i++)
        table[i] = new bool[n];

    int maxLen = 1;
    int start = 0;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
            table[i][j] = false;
    }

    // for length 1
    for(int i=0;i<n;i++)
    {
        table[0][i] = true;
    }

    //for length 2
    for(int i=0;i<n-1;i++)
    {
        if(s[i] == s[i+1])
        {
            table[1][i] = true;
            if(maxLen<2)
            {
                maxLen = 2;
                start = i;
            }
        }
    }

    //print(2,table[2],n);
    //print(1,table[1],n);
    //print(0,table[0],n);


    // for length 3 or more
    for(int len = 3;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            int j = i+len-1;
            if(table[0][i+1] && s[i]==s[j])
            {
                table[2][i] = true;
                if(maxLen<len)
                {
                    maxLen = len;
                    start = i;
                }
            }
        }

      //  cout<<"For length "<<len<<":\n";

        //print(2,table[2],n);
        //print(1,table[1],n);
        //print(0,table[0],n);

        bool *temp = table[0];
        table[0] = table[1];
        table[1] = table[2];
        table[2] = temp;
        for(int p=0;p<n;p++)
        	table[2][p] = false;
    }

    for(int i=0;i<3;i++)
        delete[] table[i];
    delete[] table;

    //return string from "start" of length maxLen
    string ans = "";
    for(int i=start;i<(start+maxLen);i++)
    {
        ans = ans + s[i];
    }

    return ans;


}
