#include "../Headers/MainHeader.h"

#include<cstdio>
#include<iostream>
using namespace std;

#define IS_A_LEAF(r) (((r)->left==NULL) && (r)->right==NULL)

void printLeft(TreeNode *r)
{
	if(r==NULL || IS_A_LEAF(r))
		return;
	printf("%d->",r->key);
	printLeft(r->left);
}

void printLeaves(TreeNode *r)
{
	if(r==NULL)
		return;
	if(IS_A_LEAF(r))
		printf("%d->",r->key);
	printLeaves(r->left);
	printLeaves(r->right);
}

void printRightReverse(TreeNode *r)
{
	if(r==NULL)
		return;
	printRightReverse(r->right);
	if(!IS_A_LEAF(r))
		printf("%d->",r->key);
}

void PrintTreeCircumference(TreeNode *root)
{
	if(root == NULL)
		return;
	printLeft(root);
	printLeaves(root);
	printRightReverse(root->right);
}
