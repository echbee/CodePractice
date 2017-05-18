//
//  Temp.cpp
//  codePractice
//
//  Created by HarpreetBansal on 09/01/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4};
    
    vector<int> v{begin(arr),end(arr)};
    
    v = {5,6,7};
    
    for(auto &i : v)
    {
        cout<<i<<endl;
    }
    
    return 0;
}

