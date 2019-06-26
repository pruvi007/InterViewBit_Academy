/*
	find the max xor pair in an array
	Idea: use a trie to traverse to the opposite bit
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
struct trieNode{
	// left for 0 and right for 1 (tracking them not actually them)
	trieNode *left,*right;
};

void insert(trieNode *root,int n)
{
	trieNode *cur = root;
	for(int i=31;i>=0;i--)
	{
		int bit = n&(1<<i);
		if(bit == 0)
		{
			if(!cur->left)
				cur->left = new trieNode;
			cur = cur->left;
		}
		else
		{
			if(!cur->right)
				cur->right = new trieNode;
			cur = cur->right;
		}
	}
}

int getMaxXor(trieNode *root,int a[],int n)
{
	
	int max_xor = INT_MIN;
	for(int i=0;i<n;i++)
	{
		int val = a[i];
		trieNode *cur = root;
		int cur_xor = 0;
		for(int j=31;j>=0;j--)
		{
			int bit = val&(1<<j);
			if(bit==0)
			{
				if(cur->right)
				{
					cur=cur->right;
					cur_xor += pow(2,j);
				}
				else cur = cur->left;
			}
			else
			{
				if(cur->left)
				{
					cur = cur->left;
					cur_xor += pow(2,j);
				}
				else cur = cur->right;
			}
		}
		if(cur_xor>max_xor)
			max_xor = cur_xor;
	}
	return max_xor;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	trieNode *root = new trieNode;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		insert(root,a[i]);
	}
	int ans = getMaxXor(root,a,n);
	cout<<ans<<endl;
}