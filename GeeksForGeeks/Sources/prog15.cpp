/*
 * prog15.cpp
 *
 *  Created on: Aug 4, 2015
 *      Author: labuser
 */

#include "../Headers/MainHeader.h"

using namespace std;

void deleteTree(TreeNode *node)
{
	if(node==NULL)
		return;
	else
	{
		deleteTree(node->left);
		deleteTree(node->right);
		delete node; //ideally... should set root node to NULL ... since client may not set it to NULL and try to access the tree again
	}
}
