#include "../Headers/MainHeader.h"
#include <iostream>

using namespace std;

void printWidth(int width)
{
	for(int i=0;i<width;i++)
		cout<<" ";
}

#define INCR_WIDTH 1

void PrintTreeImpl(TreeNode *r,int width)
{
	if(r==NULL)
	{
		printWidth(width);
		cout<<"NULL";
		return;
	}

	printWidth(width);
	cout<<r->key<<"->\n";

	//print left now
	printWidth(width+INCR_WIDTH);
	PrintTreeImpl(r->left,width+INCR_WIDTH);
	cout<<"\n";

	//print right now
	printWidth(width+INCR_WIDTH);
	PrintTreeImpl(r->right,width+INCR_WIDTH);
}

void PrintTree(TreeNode *root)
{
	PrintTreeImpl(root,1);
}
