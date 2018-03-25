#include<cstdio>
#include <limits.h>

int reverse(int A) {

    bool sign;
    long long int reverse  = 0;

    sign = (A>=0) ? false : true;

    if(sign)
        A = -A;
    printf("A is %d\n",A);

    int temp  = A;

    while(temp>0)
    {
        reverse = (long long int)(reverse*10) + (temp%10);
        temp/=10;
    }

    if(reverse>INT_MAX)
    	return 0;

    if(sign)
    {
        reverse = -reverse;
    }

    return reverse;
}
