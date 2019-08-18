/*
	Reverse Pairs
	BST solution
	- search for 2*a[i] + 1 and get the GE count of node
	- while inserting if gone right increment GE count
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
struct node{
	int val;
	int ge;
	node *left,*right;
	node(int val){
		this->val = val;
		this->ge = 1;
		this->left = this->right = NULL;
	}
};

node *insert(node *root,int val)
{
	if(root == NULL)
		return new node(val);
	if(val > root->val)
	{
		root->ge++;
		root->right = insert(root->right,val);
	}
	else if(val < root->val)
	{
		root->left = insert(root->left,val);
	}
	else
	{
		root->ge++;
	}

	return root;
}

int search(node *root,int k)
{
	if(root == NULL)
		return 0;
	if(root->val == k)
	{
		return root->ge;
	}
	else if(root->val > k)
	{
		return root->ge + search(root->left,k);
	}
	else
		return search(root->right,k);
}

int main(){
	int n; 
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	node *root = NULL;
	int c = 0;
	for(int i=0;i<n;i++)
	{
		c += search(root,2*a[i]+1);
		root = insert(root,a[i]);
	}
	cout << c << endl;

}