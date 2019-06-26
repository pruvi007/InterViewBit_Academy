/*
	Find a pair of nodes in BST whose sum is target value
	Try to use O(lgn ) space.
	We 'll modify the iterative inorder'
	Stack1 will hold normal inorder (left)
	Stack2 will hold reverse inorder(right).
	Now it will be similar to two pointers 
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

// worked in 1 go

int exist(node *root,int k)
{
	stack<node *> s1,s2;
	node *n=root,*r=root;
	while(1)
	{
		while(n)
		{
			s1.push(n);
			n = n->left;
		}
		while(r)
		{
			s2.push(r);
			r=r->right;
		}
		if(!s1.empty() && !s2.empty())
		{
			n = s1.top();
			r = s2.top();
			if(n->val!=r->val && n->val + r->val == k)
				return 1;
			else if(n->val+r->val < k)
			{
				s1.pop();
				n = n->right;
				r = NULL;
			}
			else
			{
				s2.pop();
				r = r->left;
				n = NULL;
			}
		}
		else break;
	}
	return 0;
}