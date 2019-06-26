/*
	Find tilt of a tree.
	tilt of a node = |sum(lst) - sum(rst)|
	tilt of a tree = sum(tilt of nodes)

	My approach is bottom up
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node *left,*right;
	node(int data)
	{
		this->val = data;
		this->left = this->right = NULL;
	}
};
int tilt = 0;
int tilt(node *root)
{
	if(root==NULL)
		return 0;
	int lsum = tilt(root->left);
	int rsum = tilt(root->right);

	tilt = abs(lsum - rsum);

	// we returned this to keep track of total tilt.
	return lsum + rsum + root->val;
}
