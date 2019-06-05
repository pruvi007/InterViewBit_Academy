/*
	PostOrder iterative approach
	1. using two stacks
	2. using one stack
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

// using two stacks
void PostOrder(node *root)
{
	stack<node *> s1;
	stack<node *> s2;
	s1.push(root);
	while(!s1.empty())
	{
		node *n = s1.top();
		s1.pop();
		s2.push(n);

		// we are pushing left first because while pushing to s2 left will become first and thats what we want
		if(n->left)
			s1.push(n->left);
		if(n->right)
			s1.push(n->right);

	}
	while(!s2.empty())
	{
		cout<<s2.top()->val<<" ";
		s2.pop();
	}
	cout<<endl;
}
int main()
{
	/* Constructed binary tree is 
              1 
            /   \ 
          2      3 
        /  \ 
      4     5 
    */

	node *root = new node(1); 
    root->left        = new node(2); 
    root->right       = new node(3); 
    root->left->left  = new node(4); 
    root->left->right = new node(5); 

    // my addtions
    root->right->left = new node(10);
    root->right->right = new node(11);

    PostOrder(root);
}