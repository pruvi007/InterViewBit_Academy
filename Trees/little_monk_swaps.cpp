/*
	LITTLE MONK SWAPS
	HE
	Find min swaps such that guven BT becomes BST
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

int swaps = 0;
void insert(node *root,int par,int child)
{
	if(root == NULL)
		return ;
	if(root->val == par)
	{
		if(root->left == NULL)
			root->left = new node(child);
		else root->right = new node(child); 
	}
	insert(root->left,par,child);
	insert(root->right,par,child);
}

void minSwaps(node *root)
{
	if(root == NULL)
		return ;
	if(root->left == NULL && root->right==NULL)
		return ;
	int a = root->val;
	int b,c;
	if(root->left and root->right)
	{
		b = root->left->val;
		c = root->right->val;
		if(b>a && b<c)
		{
			root->val = b;
			root->left->val = a;
			swaps++;
		}
		else if(c>a && c<b)
		{
			root->val = c;
			root->left->val = a;
			root->right->val = b;
			swaps+=2;
		}
	}
	else if(root->left and !root->right)
	{
		b = root->left->val;
		if(b > a)
		{
			root->val = b;
			root->left->val = a;
		}
	}
	else if(!root->left and root->right)
	{
		c = root->right->val;
		if(c < a)
		{
			root->val = c;
			root->right->val = a;
		}
	}
	
	minSwaps(root->left);
	minSwaps(root->right);
}
void level(node *root)
{
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		int n = q.size();
		for(int i=0;i<n;i++)
		{
			node *f = q.front();
			q.pop();
			cout << f->val << " ";
			if(f->left)
				q.push(f->left);
			if(f->right)
				q.push(f->right);
		}
		cout << endl;
		
	}
}
vector<int> a2;
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		a2.push_back(root->val);
		inorder(root->right);
	}
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	node *root = new node(a[0]);
	for(int i=1;i<n;i++)
	{
		int p = ceil((double)(i)/2.0);
		int par = a[ p- 1];
		int child = a[i];
		insert(root,par,child);
	}
	// level(root);
	// cout << endl;
	
	// minSwaps(root);
	// level(root);
	// cout << endl;
	inorder(root);
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i] != a2[i])
			swaps++;
	}
	cout << swaps << endl;
}