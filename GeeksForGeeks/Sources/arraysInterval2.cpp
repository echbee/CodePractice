#if 0

/*
 * arraysInterval2.cpp
 *
 *  Created on: Aug 21, 2015
 *      Author: labuser
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include "../Headers/MainHeader.h"

 #include <algorithm>
 using namespace std;

 bool sortOnStartTime(Interval a,Interval b)
 {
     return (a.start<b.start) ? true : false;
 }
vector<Interval> merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more detaisl
    sort(A.begin(),A.end(),sortOnStartTime);
    Interval *current = &A[0];

    vector<Interval> ans;

    for(vector<Interval>::iterator i=A.begin()+1;i<A.end();i++)
    {
        if(i->start > current->end)
        {
            ans.push_back(*current);
            current = i;
        }
        else
        {
            current->end = (current->end > i->end) ? current->end : i->end;
        }
    }

    ans.push_back(current);
    return ans;


}

#endif
