/*
	find LCA.
	This approach finds the path from root to leaf to both nodes and then start comparing.
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


// this approach uses O(n) extra space. Finds the two paths from root and then compares.
bool findPath(node *root,int x,vector<int> &a)
{
	if(root==NULL)
		return false;
	a.push_back(root->val);
	if(x == root->val)
		return true;
	if(findPath(root->left,x,a) || findPath(root->right,x,a))
		return true;
	a.pop_back();
	return false;

}

int main()
{
	// binary tree formation 
    node *root = new node(1); 
    root->left = new node(2); 
    root->right = new node(3); 
    root->left->left = new node(4); 
    root->left->right = new node(5); 
    root->right->left = new node(6); 
    root->right->right = new node(7); 
    root->left->right->left = new node(9);
    root->left->right->right = new node(10);
          
    vector<int> a,b;
    int x = 2; 
    bool hasA = findPath(root, x,a); 
 
    x = 10;
    bool hasB = findPath(root,x,b);
    if(hasA && hasB)
    {
    	for(int i=0;i<a.size();i++)
    		cout<<a[i]<<" ";
    	cout<<endl;
    	for(int i=0;i<b.size();i++)
    		cout<<b[i]<<" ";
    	cout<<endl;
    	int lca=-1;
    	int l = min(a.size(),b.size());
    	for(int i=0;i<l;i++)
    	{
    		if(a[i]!=b[i])
    		{
    			lca= a[i-1];
    			break;
    		}
    	}
    	if(lca==-1)
    	{
    		if(l==a.size())
    			lca = a[a.size()-1];
    		else lca = b[b.size()-1];
    	}
    	cout<<lca<<endl;
    }
    return 0; 
}