using namespace std;

//exponentiation by squaring method - O(log(n))
long long int PowerFunction(int base,unsigned int exp)
{
	long long int result = 1;

	while(exp)
	{
		if(exp & 1)
		{
			result*=base;
		}
		exp>>=1;
		base *= base;
	}
	return result;
}
