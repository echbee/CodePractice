//
//  Heaps.hpp
//  codePractice
//
//  Created by Harpreet Bansal on 29/08/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#ifndef Heaps_hpp
#define Heaps_hpp

#include <stdio.h>
#include <climits>
#include <cstring>
#include <deque>

using namespace std;

enum HeapType
{
    MaxHeap,
    MinHeap
};

class Heap
{
public:
    
    static Heap* createRandomHeap();
    
    Heap(const HeapType &t, const unsigned int & capacity) : mType{t}, mArrSize{capacity}, mHeapSize{0}
    {
        mArr = new int[mArrSize];
    }
    
    Heap(Heap &rhs) : Heap(rhs.mType, rhs.mArrSize)
    {
        mHeapSize = rhs.mHeapSize;
        memcpy(mArr, rhs.mArr, sizeof(int) * mArrSize);
    }
    
    void insert(int val);
    
    deque<int> heapSort();
    
    void print();
    
private:
    
    void heapify(unsigned int index);
    
    void changeKey(unsigned int keyIndex, int newKey);
    
    void expandHeap();
    
    bool keyCompare(const unsigned int &index1,const unsigned int &index2)
    {
        if(mType == MaxHeap)
            return (mArr[index1] >= mArr[index2]);
        else
            return (mArr[index1] <= mArr[index2]);
    }
    
    unsigned int getParentIndex(const unsigned int &childIndex)
    {
        if(childIndex == 0)
            return UINT_MAX;
        else
            return (childIndex-1)>>1;
    }
    
    unsigned int getLeftChildIndex(const unsigned int &parentIndex)
    {
        int leftChildIndex = (parentIndex<<2) + 1;
        
        if(leftChildIndex >= mHeapSize)
            return UINT_MAX;
        else
            return leftChildIndex;
    }
    
    unsigned int getRightChildIndex(const unsigned int &parentIndex)
    {
        int rightChildIndex = (parentIndex<<2) + 2;
        
        if(rightChildIndex >= mHeapSize)
            return UINT_MAX;
        else
            return rightChildIndex;
    }
    
    const HeapType mType;
    int mHeapSize;
    int *mArr;
    unsigned int mArrSize;
};
#endif /* Heaps_hpp */
