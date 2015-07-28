#include "../Header/MainHeader.h"

#include<iostream>

using namespace std;

int main()
{
	point p1 = {1,1};
	point p2 = {3,3};
	point p3 = {2,1};
	point p4 = {3,2};

	IfLineSegmentsIntersect(p1,p2,p3,p4);
	return 0;
}
