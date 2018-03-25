#include "../Header/MainHeader.h"

#include<iostream>

inline int CrossProduct(point p1,point p2)
{
	return (p1.x*p2.y - p2.x*p1.y);
}

point operator-(point p1,point p2)
{
	point p;
	p.x = p1.x-p2.x;
	p.y = p1.y-p2.y;
	return p;
}

int Direction(point p1,point p2,point p3)
{
	return CrossProduct(p2-p1,p3-p2);
}

bool onSegment(point p1,point p2,point p3)
{
	int minX = p1.x<p2.x?p1.x:p2.x;
	int maxX = p1.x>p2.x?p1.x:p2.x;

	int minY = p1.y<p2.y?p1.y:p2.y;
	int maxY = p1.y>p2.y?p1.y:p2.y;

	if((p3.x>=minX && p3.x<=maxX) && (p3.y>=minY && p3.y<=maxY))
		return true;
	else
		return false;
}

void IfLineSegmentsIntersect(point p1,point p2,point p3, point p4)
{
	int d1,d2,d3,d4;
	d1 = Direction(p1,p2,p3);
	d2 = Direction(p1,p2,p4);
	d3 = Direction(p3,p4,p1);
	d4 = Direction(p3,p4,p2);

	if(((d1>0 && d2<0) || (d1<0 && d2>0)) && ((d3>0 && d4<0) || (d3<0 && d4>0)))
	{
		std::cout<<"Lines Intersect";
		return;
	}

	if(d1==0 && onSegment(p1,p2,p3))
		std::cout<<"Lines Intersect";
	else if(d2==0 && onSegment(p1,p2,p4))
		std::cout<<"Lines Intersect";
	else if(d3==0 && onSegment(p3,p4,p1))
		std::cout<<"Lines Intersect";
	else if(d4==0 && onSegment(p3,p4,p2))
		std::cout<<"Lines Intersect";
	else
		std::cout<<"Lines Do Not Intersect";

}
