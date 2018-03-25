//
//  Heaps.cpp
//  codePractice
//
//  Created by Harpreet Bansal on 29/08/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#include "Heaps.hpp"

#include <iostream>

Heap* Heap::createRandomHeap()
{
    return nullptr;
}

void Heap::heapify(unsigned int index)
{
    int largestIndex = index;
    
    unsigned int leftChildIndex = getLeftChildIndex(index);
    unsigned int rightChildIndex = getRightChildIndex(index);
    if(leftChildIndex != UINT_MAX && keyCompare(leftChildIndex, largestIndex))
        largestIndex = leftChildIndex;
    
    if(rightChildIndex != UINT_MAX && keyCompare(rightChildIndex, largestIndex))
        largestIndex = rightChildIndex;
    
    if(largestIndex != index)
    {
        int temp = mArr[largestIndex];
        mArr[largestIndex] = mArr[index];
        mArr[index] = temp;
        
        heapify(largestIndex);
    }
}

void Heap::insert(int val)
{
    if(mHeapSize == mArrSize)
        expandHeap();
    
    unsigned int newKeyIndex = mHeapSize++;
    
    mArr[newKeyIndex] = (mType == MaxHeap) ? INT_MIN : INT_MAX;
    
    changeKey(newKeyIndex, val);
}

deque<int> Heap::heapSort()
{
    deque<int> sortedDeque;
    
    Heap tempHeap(*this);
    
    for(int i = tempHeap.mHeapSize - 1;i>=0;--i)
    {
        sortedDeque.push_front(tempHeap.mArr[0]);
        
        tempHeap.mArr[0] = tempHeap.mArr[i];
        tempHeap.mHeapSize--;
        tempHeap.heapify(0);
    }

    return sortedDeque;
}

void Heap::print()
{
    for(unsigned int i=0;i<mHeapSize;++i)
        cout<<mArr[i]<<" ";
    
    cout<<endl;
}

void Heap::expandHeap()
{
    int *newArr = new int[mArrSize*2];
    
    memcpy(newArr, mArr, mArrSize * sizeof(int));
    
    delete[] mArr;
    
    mArr = newArr;
    
    mArrSize = mArrSize*2;
}

void Heap::changeKey(unsigned int keyIndex, int newKey)
{
    if(keyIndex >= mHeapSize)
        return;
    
    if((mType == MaxHeap && mArr[keyIndex] > newKey) || (mType == MinHeap && mArr[keyIndex] < newKey))
        return;
    
    mArr[keyIndex] = newKey;
    
    unsigned int parentIndex;
    while((parentIndex = getParentIndex(keyIndex)) != UINT_MAX && keyCompare(keyIndex, parentIndex))
    {
        int temp = mArr[parentIndex];
        mArr[parentIndex] = mArr[keyIndex];
        mArr[keyIndex] = temp;
        
        keyIndex = parentIndex;
    }
}
