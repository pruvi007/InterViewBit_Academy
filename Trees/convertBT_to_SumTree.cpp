/*
	convert an arbitary bt to a tree that holds children sum property
	Note: You can only increment values
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

node *increment(node *root,int d)
{
	node *temp = root->left;
	while(temp)
	{
		temp->val += abs(d);
		temp = temp->left;
	}
	return root;
}
node *conv_sum_tree(node *root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL))
		return NULL;
	conv_sum_tree(root->left);
	conv_sum_tree(root->right);
	int lval=0,rval=0,diff;
	if(root->left)
		lval = root->left->val;
	if(root->right)
		rval = root->right->val;
	diff = root->val - abs(lval+rval);
	// just increase the root.val by diff to match the sum
	if(diff < 0)
		root->val += abs(diff);

	// only increment left values (you can either increase the right value , upto ur choice.)
	if(diff > 0)
	{
		root = increment(root,diff);
	}
	return root;
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
	node *root = NULL;
	root = new node(5);
	root->left = new node(2);
	root->right = new node(10);
	root->left->left = new node(1);
	root->left->right = new node(5);
	root->right->left = new node(5);
	root->right->right = new node(5);

	inorder(root);
	cout<<endl;
	root = conv_sum_tree(root);
	inorder(root);
	cout<<endl;
}


/*
	MY_IB SOLUTION
	#define ll long long int
	TreeNode *increment(TreeNode *root,int d)
	{
	    TreeNode *t = root;
	    int flag=0;
	    while(t)
	    {
	        if(t->left)
	            t = t->left;
	        else
	            t=t->right;
	        if(t)
	            t->val += abs(d);
	        
	    }
	    
	}
	TreeNode *conv_sum_tree(TreeNode *root)
	{
	    // if null or leaf return
	    if(root==NULL || (root->left==NULL && root->right==NULL))
	        return root;
	    conv_sum_tree(root->left);
	    conv_sum_tree(root->right);
	    ll lval=0,rval=0,diff;
	    if(root->left)
	        lval = root->left->val;
	    if(root->right)
	        rval = root->right->val;
	    diff = root->val - (lval+rval);
	    // just make root the sum of l and r
	    if(diff<0)
	    {
	        root->val += abs(diff);
	    }
	    else
	    {
	        root = increment(root,diff);
	    }
	    return root;
	}
	TreeNode* Solution::solve(TreeNode* A) {
	    return conv_sum_tree(A);
	}

*/