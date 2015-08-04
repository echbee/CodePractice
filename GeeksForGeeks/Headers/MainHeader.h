#ifndef _MAIN_HEADER
#define _MAIN_HEADER

#include<iostream>
#include "MyStack.h"
#include "MyTree.h"

void InfixToPostfix();

void PrintTree(TreeNode*);
void RemoveHalfNodes(TreeNode *r, TreeNode *parent, TreeNode *root);

void PrintTreeCircumference(TreeNode *root);

void CountBinaryStrings();

#endif
