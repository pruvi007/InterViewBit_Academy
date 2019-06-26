/*
	Flatten binary tree
	1. do inorder and adjust pointers (not a good Idea)
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

vector<int> in;
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		in.push_back(root->val);
		inorder(root->right);
	}
}
node *flatten()
{
	node *r2 = new node(in[0]);
	node *temp = r2;
	for(int i=1;i<in.size();i++)
	{
		node *n = new node(in[i]);
		temp->right = n;
		temp = n;
	}
	return r2;

}
int main()
{

}