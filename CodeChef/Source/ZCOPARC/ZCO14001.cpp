//
//  ZCO14001.cpp
//  codePractice
//
//  Created by HarpreetBansal on 26/03/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int ulli ;

void printVec(vector<ulli> vec)
{
    for(vector<ulli>::iterator it = vec.begin();it!=vec.end();it++)
    {
        cout<<*it<<" ";
    }
}

void ZCO14001()
{
    ulli n,h;
    cin>>n>>h;
    vector<ulli> vec;
    
    for(;n>0;n--)
    {
        ulli temp;
        cin>>temp;
        vec.push_back(temp);
    }
    
    
    ulli position = 0;
    bool isHolding = false;
    
    int command;
    cin>>command;
    
    while(true)
    {
        switch(command)
        {
            case 1:
            {
                position = (position == 0) ? position : position - 1;
                break;
            }
            case 2:
            {
                position = (position == (vec.size()-1)) ? position : position + 1;
                break;
            }
            case 3:
            {
                if(!isHolding && vec[position] > 0)
                {
                    vec[position]--;
                    isHolding = true;
                }
                break;
            }
            case 4:
            {
                if(isHolding && vec[position] < h)
                {
                    vec[position]++;
                    isHolding = false;
                }
                break;
            }
                
            case 0:
            default:
            {
                printVec(vec);
                return;
            }
                
        }
        
        cin>>command;
    }
    
}
