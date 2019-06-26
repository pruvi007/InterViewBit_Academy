/*
	Word Queries-> Hackerearth
	Find no. of words which has the prefix as queried word
	Ans.-> Implement using Trie (map Version)
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
	map<char,TrieNode *> child;
	map<char,int> f;
	bool end;
};

TrieNode *getTrieNode()
{
	TrieNode *temp = new TrieNode;
	temp->end = false;
	return temp;
}
TrieNode *root = NULL;

void insert(string s)
{
	if(root==NULL)
		root = getTrieNode();
	TrieNode *cur = root;
	int l = s.length();
	for(int i=0;i<l;i++)
	{
		char x = s[i];
		TrieNode *n = cur->child[x];
		if(n==NULL)
		{
			n = getTrieNode();
			cur->child[x] = n;
			cur->f[x] = 1;
		}
		else
			cur->f[x]++;
		cur = n;
	}
	cur->end = true;
}

int getCount(string s)
{
	int l = s.length();
	TrieNode *cur = root;
	int c=0;
	for(int i=0;i<l;i++)
	{
		char x = s[i];
		TrieNode *n = cur->child[x];
		if(!n)
			return 0;
		else
			c = cur->f[x];
		cur = n;
	}
	return c;
}

int main()
{
	int n,q;
	cin>>n>>q;
	string s[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		insert(s[i]);
	}
	for(int i=0;i<q;i++)
	{
		string x;
		cin>>x;
		cout<<getCount(x)<<endl;
	}
}