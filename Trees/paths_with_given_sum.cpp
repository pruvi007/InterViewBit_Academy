/*
	find paths with given sum
	1. find all paths then get sums of each path. (tle)
	2. While finding path keep track of sums
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

vector<vector<int> > v;
vector<int> temp;
int getPaths(node *root,int sum)
{
	if(root==NULL)
		return 0;
	temp.push_back(root->val);
	sum = sum - root->val;
	if(root->left==NULL && root->right==NULL && sum==0)
		return 1;
	if(getPaths(root->left,sum) || getPaths(root->right,sum))
		return 1;
	sum = sum - temp[temp.size()-1];
	temp.pop_back();
	return 0;

}
int main()
{

	  node *root = new node(10); 
	  root->left        = new node(8); 
	  root->right       = new node(2); 
	  root->left->left  = new node(3); 
	  root->left->right = new node(5); 
	  root->right->left = new node(2); 
	  if(getPaths(root,14))
	  {
	  	for(int i=0;i<temp.size();i++)
	  		cout<<temp[i]<<" ";
	  	cout<<endl;
	  }

}


// all paths with given sum

/*
	
#define ll long long int
vector<TreeNode *> leaf;
vector<vector<int> > v;
vector<int> temp;

void getLeaf(TreeNode *root,int sum)
{
    if(root==NULL)
        return;
    temp.push_back(root->val);
    sum = sum - root->val;
    if(root->left==NULL && root->right==NULL && sum==0)
    {
        
        v.push_back(temp);
    }
    getLeaf(root->left,sum);
    getLeaf(root->right,sum);
    sum = sum + temp[temp.size()-1];
    temp.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    leaf.clear();
    v.clear();
    getLeaf(A,B);
    
    return v;
    
    
}

*/