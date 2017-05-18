//
//  Trees.cpp
//  codePractice
//
//  Created by HarpreetBansal on 06/05/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#include "Trees.hpp"

void set_child(tree_node* &root, tree_node* leftNode,tree_node* rightNode)
{
    root->left = leftNode;
    root->right = rightNode;
}

tree_node* create_sample_tree()
{
    tree_node *node1 = new tree_node{1,nullptr,nullptr};
    tree_node *node2 = new tree_node{2,nullptr,nullptr};
    tree_node *node3 = new tree_node{3,nullptr,nullptr};
    tree_node *node4 = new tree_node{4,nullptr,nullptr};
    tree_node *node5 = new tree_node{5,nullptr,nullptr};
    tree_node *node6 = new tree_node{6,nullptr,nullptr};
    tree_node *node7 = new tree_node{7,nullptr,nullptr};
    tree_node *node8 = new tree_node{8,nullptr,nullptr};
    tree_node *node9 = new tree_node{9,nullptr,nullptr};
    tree_node *node10 = new tree_node{10,nullptr,nullptr};
    tree_node *node11 = new tree_node{11,nullptr,nullptr};
    
    set_child(node1, node2, node3);
    set_child(node2, node4, node5);
    set_child(node3, node6, nullptr);
    set_child(node6, nullptr, node7);
    set_child(node7, nullptr, node8);
    set_child(node8, node9, nullptr);
    set_child(node9, node10, node11);
    
    return node1;
    
}

#include <stack>
using namespace std;

void preorder_iterative(tree_node *root)
{
    if(root == nullptr)
        return;
    
    stack<tree_node*> stk;
    
    while(1)
    {
        while(root)
        {
            cout<<root->data<<" ";
            stk.push(root);
            root = root->left;
        }
        
        if(stk.empty())
        {
            break;
        }
        root = stk.top();
        stk.pop();
        
        root = root->right;
    }
    
    cout<<endl;
}

void postorder_iterative(tree_node *root)
{
    if(root == nullptr)
        return;
    
    stack<tree_node*> stk;
    
    tree_node *prevNode = nullptr;
    
    while(1)
    {
        while(root)
        {
            stk.push(root);
            root = root->left;
        }
        
        if(stk.empty())
        {
            break;
        }
        
        root = stk.top();
        stk.pop();
        
        
        
        root = root->right;
    }
    
    cout<<endl;
}

void insert_to_binary_tree(tree_node** root,const int& data)
{
    tree_node *newNode = new tree_node{data,nullptr,nullptr};
    if(*root == nullptr)
    {
        *root = newNode;
        return;
    }
    std::queue<tree_node*> q;
    
    q.push(*root);
    
    while(!q.empty())
    {
        tree_node *node = q.front();q.pop();
        if(node->left != nullptr && node->right != nullptr)
        {
            q.push(node->left);q.push(node->right);
            continue;
        }
        else
        {
            if(node->left == nullptr)
                node->left = newNode;
            else
                node->right = newNode;
            break;
        }
    }
}

std::list<std::list<int>> reversedLevelOrder(tree_node *root)
{
    std::list<std::list<int>> result;
    
    std::list<int> tempList;
    
    if(root == nullptr)
        return result;
    
    std::queue<tree_node*> q;
    
    q.push(root);
    q.push(nullptr);
    
    while(!q.empty())
    {
        tree_node *node = q.front();q.pop();
        
        if(node != nullptr)
            tempList.push_back(node->data);
        else
        {
            std::list<int> finalList{tempList};
            result.push_back(finalList);
            tempList.erase(tempList.begin(), tempList.end());
            
            if(!q.empty())
                q.push(nullptr);
            continue;
        }
        
        if(node->left != nullptr)
            q.push(node->left);
        if(node->right != nullptr)
            q.push(node->right);
    }
    
    result.reverse();
    
    return result;
}

int sizeOfBinaryTree(tree_node *root)
{
    if(root == nullptr)
        return 0;
    
    return 1+sizeOfBinaryTree(root->left)+sizeOfBinaryTree(root->right);
}

bool hasPathSum(tree_node *root,int sum)
{
    if(sum == 0)
        return true;
    
    if(root == nullptr)
        return false;
    
    return (hasPathSum(root->left, sum-root->data) || hasPathSum(root->right, sum-root->data));
    
}

void printRootToLeafPaths(tree_node *root, tree_node **arr, int len)
{
    if(root == nullptr)
        return;
    
    if(root->left == nullptr && root->right==nullptr)
    {
        for(int i=0;i<len;i++)
        {
            cout<<arr[i]->data<<" ";
        }
        cout<<root->data<<std::endl;
        return;
    }
    else
    {
        arr[len] = root;
        printRootToLeafPaths(root->left, arr, len+1);
        printRootToLeafPaths(root->right, arr, len+1);
    }
}
