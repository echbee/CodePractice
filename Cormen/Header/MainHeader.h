#ifndef _HEADER
#define _HEADER

#include<string>

using namespace std;

struct point
{
	int x;
	int y;
};

void NaiveStringMatching();
long long int PowerFunction(int base,unsigned int exp);

void RabinKarpMatching(string pattern,string text);

void IfLineSegmentsIntersect(point p1,point p2,point p3, point p4);

#endif
