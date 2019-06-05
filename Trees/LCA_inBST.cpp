/*
	find LCA in a BST
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
struct node {
	int val;
	node *left,*right;
	node(int data)
	{
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};

node *getLCA(node *root,int a,int b)
{
	if(root==NULL)
		return NULL;
	// if root->val is greater than both than search in left
	if(root->val>a && root->val>b)
		return getLCA(root->left,a,b);
	// if root->val is less than both search in right
	if(root->val<a && root->val<b)
		return getLCA(root->right,a,b);

	// if root->val lies in between then this is the LCA.
	return root;
}
int main()
{
	node *root = new node(20);
	root->left = new node(10);
	root->right = new node(30);
	root->left->left = new node(5);
	root->left->right = new node(15);
	root->left->right->left = new node(12);
	root->left->right->right = new node(18);

	node *lca = getLCA(root,12,5);
	cout<<lca->val<<endl;

}