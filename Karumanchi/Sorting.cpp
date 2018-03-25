//
//  Sorting.cpp
//  codePractice
//
//  Created by Harpreet Bansal on 09/07/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#include "Sorting.hpp"

void BubbleSort(vector<int> &vec)
{
    for(auto pass = vec.size()-1;pass>0;--pass)
    {
        for(decltype(pass) i = 0;i<pass;++i)
        {
            if(vec[i] > vec[i+1])
                swap(vec[i], vec[i+1]);
        }
    }
}

void SelectionSort(vector<int> &vec)
{
    for(vector<int>::size_type i = 0;i<vec.size();++i)
    {
        vector<int>::size_type minElemIndex = i;
        for(vector<int>::size_type j=i+1;j<vec.size();++j)
        {
            if(vec[j] < vec[minElemIndex])
                minElemIndex = j;
        }
        
        swap(vec[i], vec[minElemIndex]);
    }
}

vector<int>::iterator partition(vector<int> &vec,vector<int>::iterator startIter, vector<int>::iterator endIter)
{
    vector<int>::iterator midValueIter = (endIter-1);
    
    vector<int>::iterator lessThanMidEndIter = startIter;
    
    vector<int>::iterator greaterThanMidEndIter;
    
    for(greaterThanMidEndIter = startIter;greaterThanMidEndIter!=(endIter-1);++greaterThanMidEndIter)
    {
        if(*greaterThanMidEndIter <= *midValueIter)
        {
            swap(*lessThanMidEndIter, *greaterThanMidEndIter);
            ++lessThanMidEndIter;
        }
    }
    
    swap(*lessThanMidEndIter,*midValueIter);
    
    return lessThanMidEndIter;
}

void QuickSort(vector<int> &vec,vector<int>::iterator startIter, vector<int>::iterator endIter)
{
    if(endIter != startIter)
    {
        vector<int>::iterator midIter = partition(vec,startIter,endIter);
        
        QuickSort(vec, startIter, midIter);
        QuickSort(vec, midIter+1, endIter);
        
    }
}


