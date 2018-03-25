#include <iostream>
using namespace std;

int a0[] = {0};
int a1[] = {1};
int a2[] = {2,4,8,6};
int a3[] = {3,9,7,1};
int a4[] = {4,6};
int a5[] = {5};
int a6[] = {6};
int a7[] = {7,9,3,1};
int a8[] = {8,4,2,6};
int a9[] = {9,1};

void LASTDIG()
{
	int **arr = new int*[10];
		int len[10] = {1,1,4,4,2,1,1,4,4,2};
		arr[0] = a0;
		arr[1] = a1;
		arr[2] = a2;
		arr[3] = a3;
		arr[4] = a4;
		arr[5] = a5;
		arr[6] = a6;
		arr[7] = a7;
		arr[8] = a8;
		arr[9] = a9;

		int t,num,i;
		long long int a,b;
		cin>>t;
		for(;t>0;t--)
		{
			cin>>a>>b;
			num = a%10;
			if(b==0)
			{
				cout<<1<<endl;
				continue;
			}
			i = (b-1)%(len[num]);
			cout<<arr[num][i]<<endl;
		}

}
