#ifndef __MY_TREE__

#define __MY_TREE__

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

#endif
