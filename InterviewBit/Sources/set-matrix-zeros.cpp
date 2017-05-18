//
//  set-matrix-zeros.cpp
//  codePractice
//
//  Created by HarpreetBansal on 09/03/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#include <stdio.h>
#include "../headers/MainHeader.h"

void setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int buf_num = 5;
    
    for(int rowN = 0;rowN < A.size() ; rowN++)
    {
        for(int colN = 0; colN < A[rowN].size(); colN++)
        {
            if(((A[rowN][colN])%buf_num) == 0)
            {
                A[rowN][0] += buf_num;
                A[0][colN] += buf_num;
            }
        }
    }
    
    for(int rowN = 0; rowN < A.size(); rowN++)
    {
        if(A[rowN][0] >= buf_num)
        {
            for(int col = 0; col<A[rowN].size(); col++)
                A[rowN][col] = 0;
        }
    }
    
    for(int colN = 0; colN < A[0].size(); colN++)
    {
        if(A[0][colN] >= buf_num)
        {
            for(int row = 0; row<A.size(); row++)
                A[row][colN] = 0;
        }
    }
    
    
}
