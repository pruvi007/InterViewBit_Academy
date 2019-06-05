/*
	remove nodes from path whose sum path is less than k
	Idea: recursively call left and right subtree and keep decrementing k, when it reaches leaf then do the required
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

node *remove(node *root,int k)
{
	if(root==NULL)
		return NULL;
	root->left = remove(root->left,k-root->val);
	root->right = remove(root->right,k-root->val);

	if(root->left==NULL && root->right==NULL)
	{
		if(root->val<k)
		{
			free(root);
			return NULL;
		}
	}
	return root;
}
void levelOrder(node *root)
{
	queue<node *> q,temp;
	q.push(root);
	while(!q.empty())
	{
		int n = q.size();
		temp = q;
		while(!temp.empty())
		{
			cout<<temp.front()->val<<" ";
			temp.pop();
		}
		cout<<endl;
		for(int i=0;i<n;i++)
		{
			node *n = q.front();
			q.pop();
			if(n->left)
				q.push(n->left);
			if(n->right)
				q.push(n->right);
		}
		
	}
}

int main()
{
	int k = 45; 
    node *root = new node(1); 
    root->left = new node(2); 
    root->right = new node(3); 
    root->left->left = new node(4); 
    root->left->right = new node(5); 
    root->right->left = new node(6); 
    root->right->right = new node(7); 
    root->left->left->left = new node(8); 
    root->left->left->right = new node(9); 
    root->left->right->left = new node(12); 
    root->right->right->left = new node(10); 
    root->right->right->left->right = new node(11); 
    root->left->left->right->left = new node(13); 
    root->left->left->right->right = new node(14); 
    root->left->left->right->right->left = new node(15); 

    levelOrder(root);
    node *mod = remove(root,k);
    cout<<endl;
    levelOrder(mod);


}