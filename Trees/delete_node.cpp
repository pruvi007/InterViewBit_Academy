/*
	delete a node in a binary tree.
	approach-> replace the node with its inorder successor.
*/
// solution By @pruvi007
#include<bits/stdc++.h>
using namespace std;

srtuct node{
	int val;
	node *left,*right;
	node(int data){
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
node *deleteNode(node *root,int x)
{
	if(root==NULL)
		return NULL;
	if(root->val > x)
		root->left = deleteNode(root->left,x);
	else if(root->val<x)
		root->right = deleteNode(root->right,x);
	else
	{
		if(root->left==NULL)
		{
			node *temp = root->right;
			free(root);
			return temp;

		}
		else if(root->right==NULL)
		{
			node *temp = root->left;
			free(root);
			return temp;
		}

		node *temp = getMin(root->right);
		root->val = temp->val;
		root->right = deleteNode(root->right,temp->val);
	}
	return root;
}

int main()
{
	
}