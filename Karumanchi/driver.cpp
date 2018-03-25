//
//  driver.cpp
//  codePractice
//
//  Created by HarpreetBansal on 04/05/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.hpp"
#include "Trees.hpp"
#include "Sorting.hpp"
#include "Heaps.hpp"

void SLLTester()
{
    SLL *head = nullptr;
    insert(&head, 5, 2);
    insert(&head, 4, 3);
    insert(&head, 3, 1);
    insert(&head, 2, 4);
    insert(&head, 1, 2);
    
    print(head);
    
    reverse(&head);
    
    print(head);
}

void CLLTester()
{
    CLL *head = nullptr;
    insert(&head, 5, 2);
    insert(&head, 4, 3);
    insert(&head, 3, 1);
    insert(&head, 2, 4);
    insert(&head, 1, 2);
    
    print(head);
    
    /*del(&head, 4);
     print(head);
     del(&head, 0);
     print(head);
     del(&head,1);
     print(head);
     */
}

void treeTester()
{
    Tree_Node *root = BSTOperations::create_sample_BST();
    
    BinaryTreeOperations::inorder(root);
    cout<<endl;
    root = BSTOperations::deletion(root, 14);
    root = BSTOperations::deletion(root, 1);
    
    BinaryTreeOperations::inorder(root);
    
}

void heapTester()
{
    Heap myHeap(HeapType::MinHeap,1);
    
    myHeap.insert(4);
    myHeap.insert(8);
    myHeap.insert(2);
    myHeap.insert(1);
    myHeap.insert(3);
    
    myHeap.print();
    
    deque<int> sorted = myHeap.heapSort();
    
    for(auto it = sorted.begin();it!=sorted.end();++it)
        cout<<*it<<" ";
    cout<<endl;
}

void sortingTester()
{
    
    vector<int> vec = {4,5,2,1,3};
    
    //>>bubbleSort
    //BubbleSort(vec);
    //<<BubbleSort
    
    //>>selectionSort
    //SelectionSort(vec);
    //<<selectionSort
    
    //>>QuickSort
    QuickSort(vec, vec.begin(), vec.end());
    //<<QuickSort
    
    for(auto &elem : vec)
    {
        cout<<elem<<" ";
    }
    cout<<endl;
}

int main()
{
    heapTester();
}
