/*
 * prog16.cpp
 *
 *  Created on: Aug 7, 2015
 *      Author: labuser
 */

#include "../Headers/MainHeader.h"
#include <iostream>

using namespace std;

void booleanMatrix(int matrix[][4],int rowN,int colN)
{
	int rowHasOne, colHasOne;

	rowHasOne = colHasOne = 0;

	for(int i=0;i<colN;i++)
	{
		if(matrix[0][i]==1)
		{
			rowHasOne = 1;
			break;
		}
	}

	for(int i=0;i<rowN;i++)
	{
		if(matrix[i][0]==1)
		{
			colHasOne = 1;
			break;
		}
	}

	for(int i=1;i<rowN;i++)
	{
		for(int j=1;j<colN;j++)
		{
			if(matrix[i][j] == 1)
			{
				matrix[i][0] = 1;
				matrix[0][j] = 1;
			}
		}
	}

	cout<<"RowHasOne"<<rowHasOne<<endl;
	cout<<"ColHasOne"<<colHasOne<<endl;

	cout<<"Row"<<endl;

	for(int i=0;i<colN;i++)
	{
		cout<<matrix[0][i]<<" ";
	}
	cout<<endl;

	cout<<"Col"<<endl;

		for(int i=0;i<rowN;i++)
		{
			cout<<matrix[i][0]<<" ";
		}
	cout<<endl;

	//now set the matrix

	for(int i=1;i<colN;i++)
	{
		if(matrix[0][i]==1)
		{
			for(int j=1;j<rowN;j++)
			{
				matrix[j][i] = 1; //set all in same column to 1
			}
		}
	}

	//similarly for column
	for(int i=1;i<rowN;i++)
	{
		if(matrix[i][0]==1)
		{
			for(int j=1;j<colN;j++)
			{
				matrix[i][j] = 1; //set all in same row to 1
			}
		}
	}

	//now set/reset 1st row and column
	for(int i=0;i<colN;i++)
	{
		matrix[0][i] = rowHasOne;
	}

	for(int i=0;i<rowN;i++)
	{
		matrix[i][0] = colHasOne;
	}
}
