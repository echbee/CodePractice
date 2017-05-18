//
//  Trees.hpp
//  codePractice
//
//  Created by HarpreetBansal on 06/05/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#ifndef Trees_hpp
#define Trees_hpp

#include <iostream>
#include <queue>
#include <list>
#include <stack>

struct tree_node
{
    int data;
    tree_node *left;
    tree_node *right;
};

tree_node* create_sample_tree();

void preorder_iterative(tree_node *root);

void insert_to_binary_tree(tree_node**,const int& data);

std::list<std::list<int>> reversedLevelOrder(tree_node *root);
int sizeOfBinaryTree(tree_node *root);
bool hasPathSum(tree_node *root,int sum);

void printRootToLeafPaths(tree_node *root, tree_node **arr, int len);

#endif /* Trees_hpp */
