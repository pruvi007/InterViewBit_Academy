/*
	check is given bst is full or not.
	A full BT is a bt in which either nodes are leaf or possess two child.
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

node *insert(node *root,int x)
{
	if(root==NULL)
		return new node(x);
	if(root->val > x)
		root->left = insert(root->left,x);
	else
		root->right = insert(root->right,x);
	return root;
}
int isFull(node *root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	if(root->left!=NULL && root->right!=NULL)
		return isFull(root->left) && isFull(root->right);
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		node *root = NULL;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			root = insert(root,a[i]);
		}
		cout<<isFull(root)<<endl;
	}
}