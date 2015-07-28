//============================================================================
// Name        : InterviewBit.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../headers/MainHeader.h"

#include <vector>
#include <iostream>
#include<stdio.h>
#include<limits.h>

using namespace std;

int main() {
	/*int result = reverse(-1146467285);

	int size = sizeof(result);
	printf("size of int = %d\n",size);
	printf("LONG_MAX %ld\n",INT_MAX);

	printf("result = %d\n",result); */

	//prettyPrint
	/*vector<vector<int> > ans = prettyPrint(1);

	for(vector<vector<int> >::iterator i = ans.begin();i<ans.end();i++)
	{
		for(vector<int>::iterator j = i->begin();j<i->end();j++)
		{
			cout<<*j<<" ";
		}
		cout<<endl;
	}
	*/


	//countlements
	/*
	int arr[] = {7,7,7,7,7,7};
	const vector<int> A(arr,&arr[6]);
	int result = findCount(A,7);
	cout<<result<<endl; */

	//rotatedarray
	/*int arr[] = {2,3,4,5,6,1};
	const vector<int> A(arr,&arr[6]);
	int result = findMin(A);
	cout<<result<<endl; */

	//sqrt
	/*int ans = sqrt(2147483647);
	cout<<ans<<endl ; */

	//seach2d
/*
	int a1[] = {2, 3, 4, 4, 5, 5, 6};
	int a2[] = {10, 11, 12, 13, 13, 14, 15};
	int a3[] = {16, 25, 25, 26, 28, 28, 30};
	int a4[] = {30, 32, 33, 39, 39, 40, 41};
	int a5[] = {44, 44, 47, 49, 51, 55, 57};
	int a6[] = {57, 60, 60, 61, 61, 62, 63};
	int a7[] = {64, 65, 66, 67, 68, 71, 71};
	int a8[] = {75, 77, 77, 77, 78, 79, 80};
	int a9[] = {81, 83, 84, 85, 86, 88, 88};
	int a10[] = {91, 92, 93, 93, 95, 95, 98};

	vector<int> v1(a1,a1+7);
	vector<int> v2(a2,a2+7);
	vector<int> v3(a3,a3+7);
	vector<int> v4(a4,a4+7);
	vector<int> v5(a5,a5+7);
	vector<int> v6(a6,a6+7);
	vector<int> v7(a7,a7+7);
	vector<int> v8(a7,a7+7);
	vector<int> v9(a7,a7+7);
	vector<int> v10(a7,a7+7);


	vector<vector<int> > vec;
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	vec.push_back(v5);
	vec.push_back(v6);
	vec.push_back(v7);
	vec.push_back(v8);
	vec.push_back(v9);
	vec.push_back(v10);

	int ans = searchMatrix (vec,1);
	cout<<ans<<endl;
*/
	//searchrotated
	/*int arr[] = {3,4,5,6,1,2};
	vector<int> vec(arr,arr+6);
	int ans = searchIn(vec,3);
	cout<<ans<<endl;
	*/

	//pallindrome
	/*
	string s = "race a car";
	cout<<isPalindrome(s)<<endl; */

	//count_say
	/*cout<<countAndSay(6)<<endl; */


	//atoi
	/*cout<<INT_MAX<<endl;
	cout<<INT_MIN<<endl;
	const string s("  asd214aa");
	cout<<Myatoi(s)<<endl;
	*/

	//zigzag
	//cout<<convert("PAYPALISHIRING",2)<<endl;

	//addBinary
	cout<<addBinary("100", "11")<<endl;

	return 0;
}
