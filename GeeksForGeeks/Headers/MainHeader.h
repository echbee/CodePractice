#ifndef _MAIN_HEADER
#define _MAIN_HEADER

#include<iostream>

struct TreeNode
{
	TreeNode *left,*right;
	int key;

	TreeNode(int k)
	{
		left=right=NULL;
		key = k;
	}
};

void PrintTree(TreeNode*);
void RemoveHalfNodes(TreeNode *r, TreeNode *parent, TreeNode *root);

void PrintTreeCircumference(TreeNode *root);

void CountBinaryStrings();

#endif
