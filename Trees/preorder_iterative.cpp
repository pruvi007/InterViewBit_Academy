/*
	PreOrder iterative
	Idea: create an empty stack. Push root. Then print and then push right and left to stack.
	We first push right because we want to process left first.
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
		this->left=NULL;
		this->right = NULL;
	}
};

void PreOrder(node *root)
{
	if(root==NULL)
		return;
	stack<node *> s;
	s.push(root);
	while(!s.empty())
	{
		node *n = s.top();
		cout<<n->val<<" ";
		s.pop();

		if(n->right)
			s.push(n->right);
		if(n->left)
			s.push(n->left);
	}
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

    PreOrder(root);


}