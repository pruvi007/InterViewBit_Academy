/*
	Inorder iterative
	idea->push root and keep pushing left until null
	when null print top and push top.right
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
		this->right=NULL;
	}
};

void inorder(node *root)
{
	if(root==NULL)
		return ;
	stack<node *> s;
	
	node *cur = root;
	while(cur!=NULL || !s.empty())
	{
		while(cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		cout<<cur->val<<" ";
		s.pop();
		cur = cur->right;

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

    inorder(root);
}