/*
	check whether a given binary tree is a BST or not.
	1. Do the inorder and see whether its sorted
	2. For every node get min and max values and check if it lies in between
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
		this->left = NULL;
		this->right = NULL;
	}
};

int checkBST(node *root,int min,int max)
{
	if(root == NULL)
		return 1;
	if(root->val < min || root->val > max)
		return 0;
	return (checkBST(root->left,min,root->val) && checkBST(root->right,root->val,max));
}
int main()
{

	node *root = new node(4);  
    root->left = new node(2);  
    root->right = new node(5);  
    root->left->left = new node(1);  
    root->left->right = new node(3); 

    cout<<checkBST(root,INT_MIN,INT_MAX)<<endl;
}