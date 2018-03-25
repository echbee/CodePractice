#include<stdio.h>
#include<limits.h>

using namespace std;

void PIGBANK()
{
    long long int t;
    scanf("%lld",&t);

    for(;t>0;t--)
    {
        int e,f;
        scanf("%d %d",&e,&f);
        int wt = f-e;
        int n;
        scanf("%d",&n);
        int *w = new int[n];
        int *p = new int[n];
        long long int *s = new long long int[wt+1];

        for(int i=0;i<=wt;i++)
        {
            s[i] = LONG_MAX;
        //printf("Value of s[%d] = %lld\n",i,s[i]);
        }

        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&p[i],&w[i]);

        }
        s[0] = 0;
        for(int i=1;i<=wt;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i-w[j])<0)
                    continue;
                if(s[i]>(s[i-w[j]]+p[j]))
                {
                    s[i] = s[i-w[j]]+p[j];
                }

            }
            //printf("Value of s[%d] = %lld\n",i,s[i]);
        }


        if(s[wt]!=LONG_MAX)
            printf("The minimum amount of money in the piggy-bank is %lld.\n",s[wt]);
        else
            printf("This is impossible.\n");

    }
}
