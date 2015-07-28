#include "MainHeader.h"
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

int toInt(char n)
{
	return (n-'0');
}

void ADDREV()
{
	int test;
	scanf("%d",&test);
	for(;test>0;test--)
	{
		string *remainingNum = 0;
		string num1,num2;
		int t,i,len;
		unsigned long long int result = 0;
		cin>>num1>>num2;
		bool carry = false;
		std::reverse(num1.begin(),num1.end());
		std::reverse(num2.begin(),num2.end());
		unsigned long long number1 = atoi(num1.c_str()),number2 = atoi(num2.c_str());

		result = number1+number2;
		std::stringstream out;
		out<< result;
		string resultString = out.str();
		std::reverse(resultString.begin(),resultString.end());

		for(i=0;i<resultString.length();i++)
		{
			if(resultString[i]!='0')
				break;
		}

		for(;i<resultString.length();i++)
		{
			cout<<resultString[i];
		}
		cout<<endl;
	}
}

void ADDREV_codechef()
{
	int test;
	scanf("%d",&test);
	for(;test>0;test--)
	{
		string *remainingNum = 0;
		string num1,num2;
		int t,i,len;
		unsigned long long int result = 0;
		cin>>num1>>num2;
		bool carry = false;
		for(i = 0;i<num1.length() && i<num2.length();i++)
		{
			t = (carry?1:0) + toInt(num1[i]) + toInt(num2[i]);
			if(t>=10)
			{
				t = t%10;
				carry = true;
			}
			else
			{
				carry = false;
			}

			result = result*10 + t;
		}

		if(i<num1.length())
		{
			remainingNum = &num1;
			len = num1.length();
		}
		else
		{
			remainingNum = &num2;
			len = num2.length();
		}

		for(;i<len;i++)
		{
			result = result*10 + toInt((*remainingNum)[i]) + (carry?1:0);
			carry = false;
		}

		if(carry)
		{
			result = result*10 + 1;
		}

		cout<<result<<endl;
	}
}
