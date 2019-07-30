/*
	DIstinct count
	HE
	idea: create a bst with distinct values and then count nodes in it
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	node *left,*right;
	node(int val)
	{
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

node *insert(node *root,int val)
{
	if(root == NULL)
		return new node(val);
	if(root->val > val)
		root->left = insert(root->left,val);
	if(root->val < val)
		root->right = insert(root->right,val);
	return root;
}
int count(node *root,int x)
{
	if(root == NULL)
		return 0;
	return 1 + count(root->left,x) + count(root->right,x);
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,x;
		cin >> n >> x;
		node *root = NULL;
		for(int i=0;i<n;i++)
		{
			int a;
			cin >> a;
			root = insert(root,a);
		}
		int c = count(root,x);
		if(c > x)
		{
			cout << "Average\n";
		}
		else if( c == x)
		{
			cout << "Good\n";
		}
		else
		{
			cout << "Bad\n";
		}

	}

}