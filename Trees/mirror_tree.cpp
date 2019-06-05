/*
	given a binary tree, generate its mirror tree
	approach- in a bottom up manner we will swap left and right subtree
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
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

void mirror(node *root)
{
	if(root==NULL)
		return ;
	mirror(root->left);
	mirror(root->right);

	node *temp = root->left;
	root->left = root->right;
	root->right = temp;

	
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}
int main()
{
	node *root = new node(1); 
    root->left = new node(2); 
    root->right = new node(3); 
    root->left->left = new node(4); 
    root->left->right = new node(5);

    inorder(root);
    cout<<endl;
    mirror(root);
    inorder(root);
    cout<<endl;

}