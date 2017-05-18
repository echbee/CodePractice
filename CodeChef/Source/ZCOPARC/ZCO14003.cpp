//
//  ZCO14003.cpp
//  codePractice
//
//  Created by HarpreetBansal on 26/03/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ZCO14003()
{
    int n;
    cin>>n;
    
    vector<unsigned long long int> vec;
    
    for(;n>0;n--)
    {
        unsigned long long int num;
        cin>>num;
        vec.push_back(num);
    }
    
    sort(vec.begin(), vec.end());
    
    unsigned long long int ans = 0;
    
    for(vector<unsigned long long int>::iterator it = vec.begin(); it != vec.end();it++)
    {
        unsigned long long int tempAns = (*it)*(vec.end() - it);
        if(ans <  tempAns)
        {
            ans = tempAns;
        }
    }
    
    cout<<ans;
}
