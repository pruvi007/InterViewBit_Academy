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

int getMaxXor(trieNode *root,int x)
{
	
	int max_xor = INT_MIN;
	
	trieNode *cur = root;
	int cur_xor = 0;
	vector<int> b;
	for(int j=31;j>=0;j--)
	{
		int bit = x&(1<<j);
		if(bit==0)
		{
			if(cur->left)
			{
				cur=cur->left;
				// cur_xor += pow(2,j);
				b.push_back(0);
			}
			else 
			{
				cur = cur->right;
				b.push_back(1);
			}
		}
		else
		{
			if(cur->right)
			{
				cur = cur->right;
				// cur_xor += pow(2,j);
				b.push_back(1);
			}
			else 
			{
				cur = cur->left;
				b.push_back(0);
			}
		}
	}
	int sum = 0;
	int l=0;
	for(int i=b.size()-1;i>=0;i--)
	{
		if(b[i] == 1)
			sum += pow(2,l);
		l+=1;
	}
	// cout << endl;
	return sum ;
	
	// return max_xor;
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
	int m;
	cin >> m;
	int b[m];
	for(int i=0;i<m;i++)
	{
		int x;
		cin >> x;
		int ans = getMaxXor(root,x);
		cout << ans << endl;
	}
}
