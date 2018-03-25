//
//  Trees.cpp
//  codePractice
//
//  Created by HarpreetBansal on 06/05/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#include "Trees.hpp"
#include <stack>
using namespace std;

#pragma mark = BSTOperations =

Tree_Node* BSTOperations::create_sample_BST()
{
    Tree_Node *root = BSTOperations::insertion(nullptr, 10);
    root = BSTOperations::insertion(root, 4);
    root = BSTOperations::insertion(root, 8);
    root = BSTOperations::insertion(root, 1);
    root = BSTOperations::insertion(root, 5);
    
    root = BSTOperations::insertion(root, 14);
    root = BSTOperations::insertion(root, 12);
    root = BSTOperations::insertion(root, 17);
    root = BSTOperations::insertion(root, 20);
    
    return root;
}

Tree_Node* BSTOperations::insertion(Tree_Node *root, const int &d)
{
    Tree_Node *parent = nullptr;
    
    Tree_Node *rootIter = root;
    
    while(rootIter != nullptr)
    {
        parent = rootIter;
        if(d<rootIter->data)
            rootIter = rootIter->left;
        else
            rootIter = rootIter->right;
    }
    
    Tree_Node *newNode = new Tree_Node(d,nullptr,nullptr);
    
    if(parent == nullptr)
        return newNode;
    
    if(d<parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    
    return root;
}

Tree_Node* BSTOperations::search(Tree_Node *root, const int &d)
{
    
    while(root != nullptr)
    {
        if(root->data == d)
            return root;
        else if(d<root->data)
            root = root->left;
        else
            root = root->right;
    }
    
    return root;
}

Tree_Node* BSTOperations::deletion(Tree_Node *root, const int &d)
{
    if(root == nullptr)
        return root;
    
    if(d < root->data)
        root->left = BSTOperations::deletion(root->left, d);
    else if(d > root->data)
        root->right = BSTOperations::deletion(root->right, d);
    else
    {
        if(root->left == nullptr || root->right == nullptr)
        {
            Tree_Node *newNode = (root->left == nullptr ? root->right : root->left);
            delete root;
            return newNode;
        }
        else
        {
            //both children present
            Tree_Node *tmp = BSTOperations::findMinimum(root->right);
            root->data = tmp->data;
            root->right = BSTOperations::deletion(root->right, tmp->data);
        }
    }
    
    return root;
}

Tree_Node* BSTOperations::findMinimum(Tree_Node* root)
{
    if(root == nullptr)
        return root;
    
    while(root->left != nullptr)
    {
        root = root->left;
    }
    
    return root;
}

#pragma mark = BinaryTreeOperations =

Tree_Node* BinaryTreeOperations::create_sample_tree()
{
    Tree_Node *node1 = new Tree_Node{1,nullptr,nullptr};
    Tree_Node *node2 = new Tree_Node{2,nullptr,nullptr};
    Tree_Node *node3 = new Tree_Node{3,nullptr,nullptr};
    Tree_Node *node4 = new Tree_Node{4,nullptr,nullptr};
    Tree_Node *node5 = new Tree_Node{5,nullptr,nullptr};
    Tree_Node *node6 = new Tree_Node{6,nullptr,nullptr};
    Tree_Node *node7 = new Tree_Node{7,nullptr,nullptr};
    Tree_Node *node8 = new Tree_Node{8,nullptr,nullptr};
    Tree_Node *node9 = new Tree_Node{9,nullptr,nullptr};
    Tree_Node *node10 = new Tree_Node{10,nullptr,nullptr};
    Tree_Node *node11 = new Tree_Node{11,nullptr,nullptr};
    
    node1->set_child(node2, node3);
    node2->set_child(node4, node5);
    node3->set_child(node6, nullptr);
    node6->set_child(nullptr, node7);
    node7->set_child(nullptr, node8);
    node8->set_child(node9, nullptr);
    node9->set_child(node10, node11);
    
    return node1;
    
}

Tree_Node* BinaryTreeOperations::createTreeFrom(int *inOrder,int start,int end, int *preOrder, int preOrderLen,int &preOrderIndex)
{
    if(preOrderIndex >= preOrderLen || end<=start)
        return nullptr;
    
    Tree_Node *root = new Tree_Node(preOrder[preOrderIndex++],nullptr,nullptr);
    
    int *rootIter = (std::find(inOrder+start, inOrder+end, root->data));
    
    int rootIndex = rootIter - (inOrder + start);
    
    root->left = BinaryTreeOperations::createTreeFrom(inOrder, start, start+rootIndex, preOrder, preOrderLen, preOrderIndex);
    root->right = BinaryTreeOperations::createTreeFrom(inOrder, start+rootIndex+1, end, preOrder, preOrderLen, preOrderIndex);
    
    return root;
}

void BinaryTreeOperations::preorder_iterative(Tree_Node *root)
{
    stack<Tree_Node*> stk;
    
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

void BinaryTreeOperations::inorder(Tree_Node *root)
{
    if(root)
    {
        BinaryTreeOperations::inorder(root->left);
        cout<<root->data<<" ";
        BinaryTreeOperations::inorder(root->right);
    }
}

void BinaryTreeOperations::inorder_iterative(Tree_Node *root)
{
    stack<Tree_Node*> stk;
    
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
        
        cout<<root->data<<" ";
        root = root->right;
    }
    
    cout<<endl;
}

void BinaryTreeOperations::postorder_iterative(Tree_Node *root)
{
    BinaryTreeOperations::postorder_iterative(root, [](Tree_Node *root, stack<Tree_Node*> stk){
        cout<<root->data<<" ";
    });
}

void BinaryTreeOperations::postorder_iterative(Tree_Node *root,std::function<void (Tree_Node*,stack<Tree_Node*>&)> processingFn)
{
    stack<Tree_Node*> stk;
    
    
    Tree_Node *lastNode = nullptr;
    while(true)
    {
        while(root)
        {
            stk.push(root);
            root = root->left;
        }
        
        if(stk.empty())
            break;
        else
        {
            root = stk.top();stk.pop();
            
            if(lastNode && lastNode == root->right)
            {
                processingFn(root,stk);
                
                lastNode = root;
                root = nullptr;
            }
            else
            {
                if(root->right)
                {
                    stk.push(root);
                    root = root->right;
                }
                else
                {
                    processingFn(root,stk);
                    
                    lastNode = root;
                    root = nullptr;
                }
            }
        }
    }
}

void BinaryTreeOperations::levelOrder(Tree_Node *root)
{
    if(!root)
        return;
    
    queue<Tree_Node*> q;
    
    q.push(root);
    q.push(nullptr);
    
    while(!q.empty())
    {
        Tree_Node *curr = q.front(); q.pop();
        if(curr)
        {
            cout<<curr->data<<" ";
            
            if(curr->left)
                q.push(curr->left);
            
            if(curr->right)
                q.push(curr->right);
        }
        else if(!q.empty())
        {
            cout<<endl;
            q.push(curr);
        }
    }
}

void BinaryTreeOperations::printRootToLeafPaths(Tree_Node *root)
{
    BinaryTreeOperations::postorder_iterative(root, [](Tree_Node *root, stack<Tree_Node*> stk){
        if(root->left == nullptr && root->right == nullptr)
        {
            stack<Tree_Node*> stkTemp(stk);
            list<Tree_Node*> lst;
            
            while(!stkTemp.empty())
            {
                lst.push_front(stkTemp.top());
                stkTemp.pop();
            }
            
            for_each(lst.begin(), lst.end(), [](Tree_Node* r){
                cout<<r->data<<" ";
            });
            
            cout<<root->data<<" "<<endl;
        }
    });
    
}

#if 0
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
#endif

void BinaryTreeOperations::insert_to_binary_tree(Tree_Node** root,const int& data)
{
    Tree_Node *newNode = new Tree_Node{data,nullptr,nullptr};
    if(*root == nullptr)
    {
        *root = newNode;
        return;
    }
    std::queue<Tree_Node*> q;
    
    q.push(*root);
    
    while(!q.empty())
    {
        Tree_Node *node = q.front();q.pop();
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

std::list<std::list<int>> BinaryTreeOperations::reversedLevelOrder(Tree_Node *root)
{
    std::list<std::list<int>> result;
    
    std::list<int> tempList;
    
    if(root == nullptr)
        return result;
    
    std::queue<Tree_Node*> q;
    
    q.push(root);
    q.push(nullptr);
    
    while(!q.empty())
    {
        Tree_Node *node = q.front();q.pop();
        
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

int BinaryTreeOperations::sizeOfBinaryTree(Tree_Node *root)
{
    if(root == nullptr)
        return 0;
    
    return 1+sizeOfBinaryTree(root->left)+sizeOfBinaryTree(root->right);
}

bool BinaryTreeOperations::hasPathSum(Tree_Node *root,int sum)
{
    if(sum == 0)
        return true;
    
    if(root == nullptr)
        return false;
    
    return (hasPathSum(root->left, sum-root->data) || hasPathSum(root->right, sum-root->data));
    
}

void BinaryTreeOperations::printRootToLeafPaths(Tree_Node *root, Tree_Node **arr, int len)
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
