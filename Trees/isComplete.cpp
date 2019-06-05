/*
	check if given bst is complete or not
	A complete binary tree is complete on every level except last.
	the last level may contain all nodes and all are as left as possible.

	approach- if left is not there and right is there or vice versa then not a complete tree
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

int isComplete(node *root)
{
	queue<node *> q;
	q.push(root);
	int flag=0;
	while(!q.empty())
	{
		node *t = q.front();
		q.pop();
		if(t->left)
		{
			if(flag==1)
				return 0;
			q.push(t->left);
		}
		else
			flag=1;

		if(t->right)
		{
			if(flag==1)
				return 0;
			q.push(t->right);

		}
		else
			flag=1;

	}
	return 1;
}
int main()
{
	node *root = new node(1);  
    root->left     = new node(2);  
    root->right = new node(3);  
    root->left->left = new node(4);  
    root->left->right = new node(5);  
    root->right->right = new node(6);

    cout<<isComplete(root)<<endl; 
}