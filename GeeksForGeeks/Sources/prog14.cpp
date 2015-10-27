/*
 * prog14.cpp
 *
 *  Created on: Aug 4, 2015
 *      Author: labuser
 */

#include "../Headers/MainHeader.h"
#include <iostream>

using namespace std;

bool treeIdentical(TreeNode *n1,TreeNode *n2)
{
	if(n1==NULL && n2==NULL)
		return true;
	else if((n1==NULL && n2!=NULL) || (n1!=NULL && n2==NULL))
		return false;

	//both nodes are not null here
	if(n1->key!=n2->key)
		return false;
	else
	{
		//compare left and right subtrees now
		bool compareLeft = treeIdentical(n1->left,n2->left);

		if(compareLeft==false)
			return false;

		bool compareRight = treeIdentical(n1->right,n2->right);

		if(compareRight==false)
			return false;

		return true;
	}

}
