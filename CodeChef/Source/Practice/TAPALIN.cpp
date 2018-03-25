/*
 * TAPALIN.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: labuser
 */

#include "../../Header/MainHeader.h"

#include <iostream>
//#include <unordered_map>

using namespace std;

template<typename Number>
 Number power(Number base, int exponent)
{
  int zerodir;
  Number factor;
  if (exponent < 0)
  {
    zerodir = 1;
    factor = Number(1)/base;
  }
  else
  {
    zerodir = -1;
    factor = base;
  }

  Number result(1);
  while (exponent != 0)
  {
    if (exponent % 2 != 0)
    {
      result = (result * factor) % 1000000007;
      exponent += zerodir;
    }
    else
    {
      factor = (factor *  factor) % 1000000007;
      exponent /= 2;
    }
  }
  return result;
}

unsigned long long int calculateExponent(int base, unsigned long long int exponent/*, unordered_map<long long int , long long int> &dataStore */)
{
	if(exponent == 1)
	{
	//	dataStore[base] = base;
		return base;
	}

	unsigned long long int ans = calculateExponent(base,exponent/2);
	ans = (ans*ans)%1000000007; //ans*2

	unsigned long long int finalans = (exponent%2) == 0 ? ans : (base*ans) % 1000000007;

	return finalans;
}


void TAPALIN()
{
	int t;
	cin>>t;

	//unordered_map<unsigned long long int , unsigned long long int> dataStore;

//	dataStore[1] = 26;

	for(;t>0;t--)
	{
		unsigned long long int n;
		cin>>n;


		unsigned long long int finalAns = 0;

		//unsigned long long int previousAns = 26;
		/*
		for(unsigned long long int i=2;i<=n;i++)
		{
			unsigned long long int intermediateAns = (i%2 == 0) ? calculateExponent(26,i/2) : calculateExponent(26,(i+1)/2);

			//cout<< "For length "<<i<<":"<<intermediateAns<<endl;
			ans = (previousAns + intermediateAns) % 1000000007;
		}
		*/
		//unsigned long long int finalAns = 26;

		if(n==1)
		{
			cout<<"26"<<endl;
			continue;
		}

		if(n%2) // n is odd
		{
			unsigned long long int t = (power(26,(n-1)/2) - 1)/25;
			cout<<"T is "<<t<<endl;
			t = (t * 52) % 1000000007;

			finalAns = (t + power(26,(n+1)/2) ) % 1000000007;
		}
		else
		{
			unsigned long long int temp = (power(26,n/2) - 1);
			//cout<<"Temp is "<<temp<<endl;
			unsigned long long int t = ((power(26,(n+1)/2) - 1)*52) % 1000000007;
			finalAns = (t)/25;
		}
		cout<<finalAns<<endl;
	}
	return;
}
