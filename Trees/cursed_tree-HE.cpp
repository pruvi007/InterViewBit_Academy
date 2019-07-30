/*
	Monk and the cursed Tree
	HE
	idea: get root to node paths for both X and Y, then find the max value after LCA
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

node *insert(node *root,int x)
{
	if(root == NULL)
		return new node(x);
	if(root->val > x)
		root->left = insert(root->left,x);
	else 
		root->right = insert(root->right,x);
	return root;
}


bool findPath(node *root,int n,vector<int> &a)
{
	if(root == NULL)
		return false;
	a.push_back(root->val);
	if(root->val == n)
		return true;
	if(findPath(root->left,n,a) || findPath(root->right,n,a))
		return true;
	a.pop_back();
	return false;
}
int main()
{
	int n;
	cin >> n;
	node *root = NULL;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		root = insert(root,x);
	}
	int x,y;
	cin >> x >> y;
	vector<int> a,b;
	bool hasX = findPath(root,x,a);
	bool hasY = findPath(root,y,b);
	int ind;
	for(int i=0;i<a.size();i++)
	{
		if(a[i] != b[i])
		{
			ind = i-1;
			break;
		}
	}
	int max = 0;
	for(int i=a.size()-1;i>=ind;i--)
	{
		if(a[i] > max)
			max = a[i];
	}
	for(int i=ind+1;i<b.size();i++)
	{
		if(b[i]>max)
			max = b[i];
	}
	cout << max << endl;


}