#include "../Headers/MainHeader.h"
#include<stdio.h>

void TBProg1(int *heights, int heights_length)
{
	if(heights_length==0)
		return;

	int *leftArr = new int[heights_length];
	int *rightArr = new int[heights_length];

	int maxValue = 0;
	//for left array
	for(int i=0;i<heights_length;i++)
	{
		leftArr[i] = maxValue;
		if(heights[i]>maxValue)
			maxValue = heights[i];
	}

	maxValue = 0;
	for(int i=heights_length-1;i>=0;i--)
	{
		rightArr[i] = maxValue;
		if(heights[i]>maxValue)
			maxValue = heights[i];
	}
	int final_ans = 0;

	for(int i=0;i<heights_length;i++)
	{
		int minOf2 = (leftArr[i]<rightArr[i]) ? leftArr[i] : rightArr[i];
		if(heights[i] > minOf2)
			continue;
		final_ans = final_ans + (minOf2 - heights[i]);
	}

	printf("%d",final_ans);

	delete[] leftArr;
	delete[] rightArr;
}
