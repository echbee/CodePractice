#include "../Headers/MainHeader.h"
#include <stdio.h>

void CCProg1()
{
	int arr[] = {4,4,5,6,7,6,5,5,4,3,2,3};
	int len = sizeof(arr)/sizeof(arr[0]);

	int i=0,diff=0;

	int valToFind = 2;

	bool found = false;
	while(i<len)
	{
		if(arr[i] ==valToFind)
		{
			found = true;
			break;
		}
		diff = valToFind - arr[i];
		diff = (diff>0)?diff:-diff;

		i = i+diff;
	}

	if(found)
	{
		printf("Value found");
	}
	else
	{
		printf("Value not found");
	}
}
