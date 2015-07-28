#include "../headers/MainHeader.h"

int add(int a,int b,int carry = 0)
{
	int ans ;
	if((a==0 && b==1) || (a==1 && b==0))
	{
		ans =  1;
	}

	if(a==0 && b==0)
	{
		ans =  0;
	}

	if(a==1 && b==1)
	{
		ans = 10;
	}

	if(carry==0)
		return ans;
	else
	{
		if(ans == 1)
		{
			ans = 10;
		}
		else
			ans = ans + carry;
	}

	return ans;
}

string addBinary(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size()==0)
        return B;
    if(B.size()==0)
        return A;

    long long int index1 = A.size()-1;
    long long int index2 = B.size()-1;

    string result = "";

    int carry = 0;

    while(index1>=0 || index2>=0)
    {
    	int val1;
    	int val2;

    	val1 = index1>=0 ? A.at(index1)-48 : 0;
    	val2 = index2>=0 ? B.at(index2)-48 : 0;


    	int ans = add(val1,val2,carry);

    	if(ans>=10)
    	{
    		carry = 1;
    		ans = ans %10;
    	}
    	else
    	{
    		carry = 0;
    	}

    	result = to_string(ans) + result;

    	index1--;
    	index2--;
    }

    if(carry==1)
    {
    	result = "1" + result;
    }

    return result;
}
