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
    
    tree_node *root = create_sample_tree();
    
//    preorder_iterative(root);
//    
//    std::list<std::list<int>> result = reversedLevelOrder(root);
//    
//    for(auto &aList : result)
//    {
//        for(auto &data : aList)
//        {
//            std::cout<<data<<" ";
//        }
//        std::cout<<std::endl;
//    }
//    std::cout<<sizeOfBinaryTree(root);
    
//    std::cout<<hasPathSum(root, 45)<<std::endl;
    
    tree_node **arr = new tree_node*[50];
    printRootToLeafPaths(root, arr, 0);
}

int main()
{
    treeTester();
}
