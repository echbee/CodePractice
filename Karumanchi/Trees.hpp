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
#include <functional>

struct Tree_Node
{
    int data;
    Tree_Node *left;
    Tree_Node *right;
    
    Tree_Node(const int &d, Tree_Node *l,Tree_Node *r) : data{d}, left{l}, right{r}
    {
        
    }
    
    void set_child(Tree_Node* leftNode,Tree_Node* rightNode)
    {
        this->left = leftNode;
        this->right = rightNode;
    }
};

class BSTOperations
{
public:
    
    static Tree_Node* create_sample_BST();
    
    static Tree_Node* insertion(Tree_Node *root, const int &d);
    static Tree_Node* deletion(Tree_Node *root, const int &d);
    static Tree_Node* search(Tree_Node *root, const int &d);
    
    static Tree_Node* findMinimum(Tree_Node* root);
    
private:
    
};

class BinaryTreeOperations
{
public:

    //constructors
    static Tree_Node* create_sample_tree();
    
    static Tree_Node* createTreeFrom(int *inOrder,int start,int end, int *preOrder, int preOrderLen,int &preOrderIndex);
    
    //traversals
    static void preorder_iterative(Tree_Node *root);
    
    static void inorder_iterative(Tree_Node *root);
    
    static void inorder(Tree_Node *root);
    
    static void levelOrder(Tree_Node *root);
    
    static std::list<std::list<int>> reversedLevelOrder(Tree_Node *root);
    
    static void postorder_iterative(Tree_Node *root);
    
    static void printRootToLeafPaths(Tree_Node *root);
    
    static void printRootToLeafPaths(Tree_Node *root, Tree_Node **arr, int len);
    
    static void insert_to_binary_tree(Tree_Node**,const int& data);
    
    
    static int sizeOfBinaryTree(Tree_Node *root);
    
    static bool hasPathSum(Tree_Node *root,int sum);
    
    
private:
    
    
    static void postorder_iterative(Tree_Node *root, std::function<void (Tree_Node*, std::stack<Tree_Node*> &stk)> processingFn);
    
};

#endif /* Trees_hpp */
