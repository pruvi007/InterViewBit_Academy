/*
	Store parents of each node in a map
	To be used for the question (nodes at k diatacne)

*/ 
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node *left,*right;
	node(int val)
	{
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

map<node *,node *> m;
void mark_parents(node *root)
{
	if(root==NULL)
		return ;
	if(root->left)
		m[root->left] = root;
	if(root->right)
		m[root->right] = root;

	mark_parents(root->left);
	mark_parents(root->right);
}
int main()
{
	node *root = new node(1);
	root->left = new node(5);
	root->right = new node(6);
	root->left->left = new node(2);
	root->left->right = new node(3);
	root->right->right = new node(10);
	root->left->left->left = new node(4);

	mark_parents(root);
	map<node *,node *>::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		cout << (it->first->val) << ": " << (it->second->val) << endl;
	}

}

// nicely done (yeah........)