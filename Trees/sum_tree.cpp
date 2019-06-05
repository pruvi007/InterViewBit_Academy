/*
	find whether a given tree is a sum tree or not.
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *left,*right;
	node(int data)
	{
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};
int sum(node *n)
{
	if(n==NULL)
		return 0;
	return sum(n->left)+ n->val +sum(n->right);
}
int sumTree(node *root)
{
	// if null node or leaf node . return true.
	if(root==NULL || (root->left==NULL && root->right==NULL))
		return 1;
	// call for left and right
	int ls = sum(root->left);
	int rs = sum(root->right);

	// is ls and rs is equal then check for their left and right
	if(ls+rs == root->val)
	{
		if(sumTree(root->left) && sumTree(root->right))
			return 1;
	}
	return 0;
}
int main()
{
	node *root = new node(26);
	root->left = new node(10);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(6);
	root->right->right = new node(4);

	// O(n^2) approach.. Naively checking for left and right subtrees.
	int ans = sumTree(root);
	cout<<ans<<endl;
}