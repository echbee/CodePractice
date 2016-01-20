/*
 * points.cpp
 *
 *  Created on: Jan 5, 2016
 *      Author: labuser
 */

#include <map>
#include<iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

double findSlope(int x1,int y1,int x2,int y2)
{
	if((x2-x1) == 0)
		return 26925;
	double ans = ((double)(y2-y1))/(x2-x1);
	return ans;
}

struct point{
	int x, y;
	point(int xx,int yy)
	{
		x = xx;
		y = yy;
	}
};

class point_compare{

public:
	bool operator()(point pt1,point pt2)
	{
		return (pt1.x<pt2.x || pt1.y<pt2.y);
	}
};

int maxPoints(vector<int> &A, vector<int> &B) {
	//bool *pt(point,point) = cmp;
	map<double,set<point,point_compare> > mmap;

	map<point,int,point_compare> countMap;

	for(int i=0;i<A.size();i++)
	{
		countMap[point(A[i],B[i])]++;
		cout<<"For i="<<i<<endl;
		for(int j=0;j<A.size();j++)
		{
			if(i==j)
				continue;

			cout<<"For j="<<j<<endl;
			double slope = findSlope(A[i],B[i],A[j],B[j]);
			if(mmap.find(slope) == mmap.end())
			{
				cout<<"not found!!"<<endl;
				set<point,point_compare> s = {point(A[i],B[i]),point(A[j],B[j])};
				//s.insert(point(A[i],B[i]));
				//s.insert(point(A[j],B[j]));
cout<<"set has"<<endl;
				for(auto it2 = s.begin();it2!=s.end();it2++)
											{
												cout<<it2->x<<":"<<it2->y<<endl;
											}

				mmap[slope] = s;;
			}
			else
			{
				cout<<"Found!!"<<endl;;
				set<point,point_compare> t = mmap[slope];
				point a = point(A[i],B[i]);
				point b = point(A[j],B[j]);

				set<point,point_compare>::iterator iter = t.find(a);
				if(iter == t.end())
				{
					cout<<"Inserting "<<a.x<<":"<<a.y<<endl;
					pair<set<point>::iterator,bool > p = t.insert(a);
					//cout<<p.second<<endl;
					for(auto it2 = t.begin();it2!=t.end();it2++)
							{
								cout<<it2->x<<":"<<it2->y<<endl;
							}
					mmap[slope] = t;
				}
				iter = t.find(b);
				if(iter == t.end())
				{
					cout<<"Inserting "<<b.x<<":"<<b.y<<endl;
					pair<set<point>::iterator,bool > p = t.insert(b);
					//cout<<p.second;
					for(auto it2 = t.begin();it2!=t.end();it2++)
							{
								cout<<it2->x<<":"<<it2->y<<endl;
							}
					mmap[slope] = t;
				}
			}
		}
	}

	int ans = 0;

	for(map<double,set<point,point_compare> >::iterator it = mmap.begin(); it!=mmap.end();it++)
	{
		set<point,point_compare> s = it->second;
		int computedAns = 0;
		cout<<it->first<<" has following elements"<<endl;
		for(auto it2 = s.begin();it2!=s.end();it2++)
		{
			cout<<it2->x<<":"<<it2->y<<endl;
			computedAns+=countMap[point(it2->x,it2->y)];

		}
		if(computedAns > ans)
			ans = computedAns;
	}

	cout<<"CountMap is "<<endl;
	for(auto it2 = countMap.begin();it2!=countMap.end();it2++)
		{
			cout<<it2->first.x<<":"<<it2->first.y<<"->"<<it2->second<<endl;
			//computedAns+=countMap[point(it2->x,it2->y)];

		}


	return ans;
}
