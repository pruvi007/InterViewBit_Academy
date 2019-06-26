/*
	Populate next pointers in a BST
	1. use level order traversal but space will be O(n)
	2. take the help of uncle.
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node *left,*right,*next;
	node(int data)
	{
		this->val = data;
		this->left = NULL;
		this->right = NULL;
		this->next = NULL;
	}
};

node *getNextRight(node *root)
{
	node *temp = root->next;
	while(temp)
	{
		if(temp->left)
			return temp->left;
		if(temp->right)
			return temp->right;
		temp = temp->next;
	}
	return NULL;
}
void populate(node *root)
{
	root->next = NULL;
	node *p = root;
	while(p)
	{
		node *q = p;
		while(q)
		{
			if(q->left)
			{
				if(q->right)
				{
					q->left->next = q->right;
				}
				else
				{
				    q->left->next = getNextRight(q);
				}
			}
			if(q->right)
			{
				q->right->next = getNextRight(q);
			}
			q = q->next;
		}
		if(p->left)
			p = p->left;
		else if(p->right)
			p = p->right;
		else p = getNextRight(p);
	}
}