/*
	Find unique prefixes
	Implementation using trie;
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

struct trieNode{
	map<char,trieNode *> child;
	map<char,int> f;
	bool end;
};

trieNode *getNode()
{
	trieNode *temp = new trieNode;
	temp->end = false;
	return temp;
}

trieNode *root = NULL;
void insert(string x)
{
	if(root==NULL)
		root = getNode();

	int l = x.length();
	trieNode *curr = root;
	for(int i=0;i<l;i++)
	{
		char ch = x[i];
		trieNode *n = curr->child[ch];
		if(n==NULL)
		{
			n = getNode();
			curr->child[ch] = n;
			curr->f[ch] = 1;
		}
		else
		{
			curr->f[ch] = curr->f[ch]+1;
		}
		curr = n;
	}
	curr->end = true;
}

bool search(string x)
{
	trieNode *curr = root;
	int l = x.length();
	for(int i=0;i<l;i++)
	{
		char ch = x[i];
		trieNode *n = curr->child[ch];
		if(!n)
			return false;
		curr = n;
	}
	return curr->end;
}

string getUnique(string x)
{
	trieNode *curr = root;
	int l = x.length();
	string ans = "";
	for(int i=0;i<l;i++)
	{
		char ch = x[i];
		trieNode *n = curr->child[ch];
		int count = curr->f[ch];
		if(count==1)
		{
			ans += x[i];
			return ans;
		}
		else
		{
			ans += x[i];
		}
		curr = n;

	}
	return ans;

}
int main()
{
	int n;
	cin>>n;
	string s[n];
	root = NULL;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		insert(s[i]);
	}
	// for(int i=0;i<n;i++)
	// {
	// 	string x;
	// 	cin>>x;
	// 	cout<<search(x)<<endl;
	// }
	for(int i=0;i<n;i++)
	{
		cout<<getUnique(s[i])<<endl;
	}


}