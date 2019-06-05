/*
	print all paths to the leaf from root.
	1. i found all the leaves
	2. for each leaf i found path from root to that leaf.
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
vector<node *> leaf;
vector<vector<int> > v;
vector<int> temp;

// backtracking function to print path from root to leaf.
bool printPath(node *root,node *x)
{
	if(root==NULL)
		return false;
	temp.push_back(root->val);
	if(root == x)
		return true;
	if(printPath(root->left,x) || printPath(root->right,x))
		return true;
	temp.pop_back();
	return false;
}

void getLeaf(node *root)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
		leaf.push_back(root);
	getLeaf(root->left);
	getLeaf(root->right);
	return ;
}
int main()
{
	node *root = new node(5);
	root->left = new node(4);
	root->right = new node(8);
	root->left->left = new node(11);
	root->left->left->left = new node(7);
	root->right->left = new node(13);
	root->right->right = new node(4);
	root->right->right->left = new node(5);

	getLeaf(root);
	for(int i=0;i<leaf.size();i++)
	{
		cout<<leaf[i]->val<<" ";
		temp.clear();
		bool x = printPath(root,leaf[i]);
		v.push_back(temp);
	}
	cout<<endl;
	cout<<"Paths: \n";
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}

}



// IB function

/*vector<TreeNode *> leaf;
vector<vector<int> > v;
vector<int> temp;

bool printPath(TreeNode *root,TreeNode *x)
{
    if(root==NULL)
        return false;
    temp.push_back(root->val);
    if(root == x)
        return true;
    if(printPath(root->left,x) || printPath(root->right,x))
        return true;
    temp.pop_back();
    return false;
}
void getLeaf(TreeNode *root)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        leaf.push_back(root);
    getLeaf(root->left);
    getLeaf(root->right);
}
vector<vector<int> > Solution::solve(TreeNode* A) {
    v.clear();
    getLeaf(A);
    for(int i=0;i<leaf.size();i++)
    {
        temp.clear();
        if(printPath(A,leaf[i]))
            v.push_back(temp);
    }
    return v;
    
}*/

