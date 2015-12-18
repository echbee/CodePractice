/*
 * Main.cpp
 *
 *  Created on: Oct 27, 2015
 *      Author: labuser
 */
#include "../headers/MainHeader.h"

using namespace std;

int main()
{
	ZigZag temp;
	int arr[] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
	vector<int> v(arr,arr+19);
	cout<<temp.longestZigZag(v)<<endl;
	return 0;

}
