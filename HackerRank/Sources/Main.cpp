#if 0
#include "../Headers/MainHeader.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long int ulli;

struct node {
    int val;
    node *left,*right;
    node()
    {
        val = 0;
        left = right = NULL;
    }
    node(int v)
    {
        node();
        val = v;
    }
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ulli n,q;
    cin>>n>>q;
    vector<vector<ulli>> seqList(n);
    
    ulli lastAns = 0;
    for(;q>0;q--)
    {
        ulli qType,x,y;
        cin>>qType>>x>>y;
        if(qType == 1)
        {
            ulli seqIndex = (x^lastAns)%n;
            seqList[seqIndex].push_back(y);
        }
        else
        {
            ulli seqIndex = (x^lastAns)%n;
            ulli elementIndex = y%(seqList[seqIndex].size());
            lastAns = seqList[seqIndex][elementIndex];
            cout<<lastAns<<endl;
        }
    }
    
    return 0;
}
#endif

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isHappy(string s)
{
    if(s.length()==1)
        return false;
    
    for(int i=0;i<s.length();i++)
    {
        if(i==0 && s[i]==s[i+1])
            continue;
        else if(i== s.length()-1 && s[i] == s[i-1])
        {
            continue;
        }
        else if(i>0 && i<s.length()-1 && s[i]==s[i-1] && s[i]==s[i+1])
        {
            continue;
        }
        else
            return false;
    }
    return true;
}

bool singelElementPresent(map<char,int> &dbMap)
{
    for(map<char,int>::iterator i = dbMap.begin();i!=dbMap.end();i++)
    {
        cout<<"i->first"<<i->first<<" and i->Second="<<i->second<<endl;
        if(i->second == 1)
            return true;
    }
    return false;
}

int main(){
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        cout<<"Iteration:"<<a0<<endl;
        int n;
        cin >> n;
        string b;
        cin >> b;
        int i;
        for(i=0;i<b.length();i++)
        {
            if(b[i] == '_')
                continue;
            else
                break;
        }
        
        if(i==b.length())
        {
            cout<<"YES"<<endl;
            continue;
        }
        
        if(b.length()==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        
        map<char,int> dbMap;
        bool holePresent = false;
        for(int j=0;j<b.length();j++)
        {
            if(b[j] != '_')
            {
                dbMap[b[j]]+=1;
            }
            else
                holePresent = true;
        }
        //if happy ... return YES,,
        // else if hole not present ... return NO
        // else if  single element is there return no
        // else return yes
        if(isHappy(b))
        {
            cout<<"YES"<<endl;
            continue;
        }
        else if(!holePresent)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else if(singelElementPresent(dbMap))
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            cout<<"YES"<<endl;
            continue;
        }
        
    }
    return 0;
}
