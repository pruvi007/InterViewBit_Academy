/*
	Count Smaller element after self.
	Use BST. 
	Start from right side and (count the right movements) + (size of left subtree of each node from where you moved right).

	This code works very fine but in strict platforms its required to reduce the memory Usage. Getting MLE.
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct node{
	int val;
	int Lsize;
	int dups;
	node *left,*right;
	node(int val){
		this->val = val;
		this->Lsize = 0;
		this->dups = 0;
		this->left = this->right = NULL;
	}
};

int c = 0;
node *insert(node *root,int k)
{
	if(root == NULL)
		return new node(k);
	if(root->val > k)
	{
		root->Lsize += 1;
		root->left = insert(root->left,k);
	}
	else if(root->val < k)
	{
		c += 1 + root->Lsize + root->dups;
		root->right = insert(root->right,k);
	}
	else
	{
		c += root->Lsize;
		root->dups += 1;
	}

	return root;
}

void printInfo(node *root){
	if(root != NULL)
	{
		printInfo(root->left);
		cout << root->val << "  size: " << root->Lsize << "  dups: " << root->dups << endl;
		printInfo(root->right);
	}
}
int main(){

	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	node *root = NULL;
	vector<int> smaller;
	for(int i=n-1;i>=0;i--)
	{
		c = 0;
		root = insert(root,a[i]);
		smaller.push_back(c);
	}
	// printInfo(root);
	reverse(smaller.begin(),smaller.end());
	for(int i=0;i<smaller.size();i++)
		cout << smaller[i] << " ";
	cout << endl;

}