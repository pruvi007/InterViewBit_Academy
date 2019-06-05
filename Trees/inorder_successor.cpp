/*
	find the inorder successor of a given node
	1. using parent pointer
	2. start from root and keep track of potential answers
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
	if(root->val >= x)
		root->left = insert(root->left,x);
	if(root->val < x)
		root->right = insert(root->right,x);

	return root;
}

node *getNode(node *root,int x)
{
	if(root==NULL)
		return NULL;
	if(root->val > x)
		return getNode(root->left,x);
	if(root->val < x)
		return getNode(root->right,x);
	return root;
}


int poss_ans=INT_MAX;
int getMin(node *root)
{
	if(root->left)
		return getMin(root->left);
	return root->val;
}
void findSucc(node *root,node *x)
{
	if(x->right)
		poss_ans = getMin(x->right);
	else
	{
		if(root==NULL)
			return;
		if(root->val>=x->val)
		{
			if(root->val < poss_ans && root->val > x->val)
				poss_ans = root->val;
			findSucc(root->left,x);
		}
		if(root->val < x->val)
			findSucc(root->right,x);
	}
}
void inorder(node *root)
{
	stack<node *> s;
	s.push(root);
	while(!s.empty())
	{
		while(root->left)
		{
			s.push(root->left);
			root = root->left;
		}
		node *n = s.top();
		s.pop();
		cout<<n->val<<" ";
		if(n->right)
		{
			s.push(n->right);
			root = n->right;
		}
	}
}
int main()
{
	node *root = NULL;
	root = insert(root,20);
	root = insert(root,8);
	root = insert(root,22);
	root = insert(root,4);
	root = insert(root,12);
	root = insert(root,10);
	root = insert(root,14);
	root = insert(root,13);
	// root = inssert(root,16);

	inorder(root);
	cout<<endl;
	node *search = getNode(root,4);
	
	findSucc(root,search);
	cout<<poss_ans<<endl;
}