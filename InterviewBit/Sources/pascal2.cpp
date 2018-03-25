#include "../headers/MainHeader.h"

using namespace std;

long long int factorial(int a)
{
    long long int ans = 1;
    for(int i=2;i<=a;i++)
        ans = ans * i;
    return ans;
}

vector<int> getRow(int a) {
    vector<int> ans(a+1,0);

    ans[0] = 1;
    int prev,temp;

    for(int len=2;len<=(a+1);len++)
    {
    	prev = ans[0];
    	for(int loop = 1;loop<len;loop++)
    	{
    		temp = ans[loop] + prev;
    		prev = ans[loop];
    		ans[loop] = temp;
    	}
    }

    return ans;

    return ans;

}
