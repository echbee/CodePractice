#include "../Headers/MainHeader.h"

using namespace std;

bool isHalfNode(TreeNode *r)
{
	if((r->left==NULL && r->right!=NULL) || (r->left!=NULL && r->right==NULL))
		return true;
	return false;
}

void RemoveHalfNodes(TreeNode *r,TreeNode *parent,TreeNode *root)
{
	bool setParent = true;
	if(r==NULL)
		return;

	if(isHalfNode(r))
	{
		setParent = false;
		if(parent==NULL)
		{
			root = r->left?r->left:r->right;
		}
		else
		{
			if(parent->left==r)
			{
				parent->left = r->left?r->left:r->right;
			}
			else
			{
				parent->right = r->left?r->left:r->right;
			}
		}
	}

	if(setParent)
	{
		parent = r;
	}

	RemoveHalfNodes(r->left,parent,root);
	RemoveHalfNodes(r->right,parent,root);
}
