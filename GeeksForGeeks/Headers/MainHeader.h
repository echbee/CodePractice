#ifndef _MAIN_HEADER
#define _MAIN_HEADER

#include<iostream>
#include "MyStack.h"
#include "MyTree.h"
#include <string>
#include <vector>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

void InfixToPostfix();

void PrintTree(TreeNode*);
void RemoveHalfNodes(TreeNode *r, TreeNode *parent, TreeNode *root);

void PrintTreeCircumference(TreeNode *root);

void CountBinaryStrings();

bool treeIdentical(TreeNode *node1,TreeNode *node2);

void deleteTree(TreeNode *node);

void booleanMatrix(int matrix[][4],int rowN,int colN);

void permute(string s,int index);

int titleToNumber(string A);

int firstMissingPositive(vector<int> &A);

#endif
