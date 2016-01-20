/*
 * YNOUTPUT.cpp
 *
 *  Created on: Jan 19, 2016
 *      Author: labuser
 */

#include "../Header/MainHeader.h"

#include <iostream>
#include <stdio.h>

#define gc getchar

using namespace std;

bool IsAMatch(bool *lhs,bool *rhs,int lhsStart,int rhsStart,int length,bool desiredAns)
{
	//cout<<"Inside IsAMatch with length:"<<length<<endl;;
	if(length<=0)
		return true;
	bool ans = true;
	for(int i=0;i<length;i++)
	{
		if(lhs[lhsStart+i] != rhs[rhsStart+i])
		{
			ans = false;
			break;
		}
	}

	if(ans == desiredAns)
		return true;
	else
		return false;
}

void YNOUTPUT()
{
	int numT;
	scanf("%d",&numT);
	gc();
	bool **arr = new bool*[numT];

	for(int t = 0;t<numT;t++)
	{
		arr[t] = new bool[numT];

		for(int tIn = 0;tIn<numT;tIn++)
		{
			char c;
			c = gc();
			arr[t][tIn] = (c=='Y' ? true : false) ;
			if(c== 'Y')
			{
				gc();gc();gc();
			}
			else
			{
				gc();gc();
			}
		}
	}

	/*cout<<"arr is "<<endl;
	for(int i=0;i<numT;i++)
	{
		for(int j=0;j<numT;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl; */

	bool *output = new bool[numT];
	bool deleteOutput = true;

	for(int i=0;i<numT;i++)
	{
		//cout<<"For i="<<i<<endl;
		if(arr[i][i] == true)
		{
			//cout<<"2"<<endl;
			if(IsAMatch(output,arr[i],0,0,i-1,true))
			{
				//cout<<"1"<<endl;
				bool completeMatch = true;
				for(int p=i+1;p<numT;p++)
				{
					if(!IsAMatch(arr[i],arr[p],0,0,numT,arr[i][p]))
					{
						completeMatch = false;
						break;
					}
				}
				if(completeMatch)
				{
					output = arr[i];
					deleteOutput = false;
					break;
				}
				else
				{
					output[i] = false;
					continue;
				}
			}
			else
			{
				//cout<<"3"<<endl;
				output[i] = false;
				continue;
			}
		}
		else
		{
			output[i] = false;
			continue;
		}
	}


	//print output
	for(int i=0;i<numT;i++)
		cout<< ((output[i] == true) ? "YES" : "NO") << endl;

	//deleting the array
	for(int i=0;i<numT;i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	if(deleteOutput)
		delete[] output;
}
