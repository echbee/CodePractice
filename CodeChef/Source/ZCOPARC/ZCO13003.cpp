//
//  ZCO13003.cpp
//  codePractice
//
//  Created by HarpreetBansal on 26/03/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long int ulli ;

void ZCO13003()
{
    ulli n,k;
    cin>>n>>k;
    
    vector<ulli> vec;
    for(ulli cnt=0 ; cnt<n ;cnt++)
    {
        ulli temp;
        cin>>temp;
        vec.push_back(temp);
    }
    
    sort(vec.begin(),vec.end());
    
    vector<ulli>::iterator i,j;
    i = vec.begin();
    j = vec.end() - 1;
    
    ulli ans = 0;
    
    
    while(j >= vec.begin())
    {
        if((*i) + (*j) < k)
        {
            while((*i + *j < k) && i<j)
            {
                i++;
            }
            
            if(i==j)
            {
                ulli t = j - vec.begin() + 1;
                
                ans += (t*(t-1)/2);
                break;
            }
            
            i--;
            ans += (i - vec.begin() + 1);
        }
        
        j--;
    }
    
    cout<<ans;
    
}
