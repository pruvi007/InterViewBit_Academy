/*
	implement trie datastructure

	contains map and next pointer(due to map its very efficient)
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

struct trieNode{
	map<char,trieNode *> child;
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
	if(root == NULL)
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
		}
		curr = n;
	}
	curr->end = true;
}

bool search(string x)
{
	if(root==NULL)
		return false;

	int l = x.length();
	trieNode *curr = root;
	for(int i=0;i<l;i++)
	{
		char ch = x[i];
		trieNode *n = curr->child[ch];
		if(!n)
			return false;
		curr = n;
	}
	if(curr->end==true)
		return true;
	return false;
}

int main()
{
	
	string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 

    
    for(int i=0;i<8;i++)
    	insert(keys[i]);

    bool ans = search("ther");
    cout<<ans<<endl;
}