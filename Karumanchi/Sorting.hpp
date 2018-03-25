//
//  Sorting.hpp
//  codePractice
//
//  Created by Harpreet Bansal on 09/07/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#ifndef Sorting_hpp
#define Sorting_hpp

#include "../CommonHeaders.h"

void BubbleSort(vector<int> &vec);

void SelectionSort(vector<int> &vec);

void QuickSort(vector<int> &vec,vector<int>::iterator startIter, vector<int>::iterator endIter);

#endif /* Sorting_hpp */
