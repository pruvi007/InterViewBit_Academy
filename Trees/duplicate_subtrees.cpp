/*
	Duplicate Subtrees
	Serialize the tree recursively and check if either SerLST or SerRST is present in a map or not

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

map<string,int> m;
char marker = '#';
string isDup(node *root)
{
	string s = "";
	if(root == NULL)
	{
		return s+marker;
	}
	// check if LST has duplicate
	string lst = isDup(root->left);
	if(lst == s)
		return s;
	// check if RST has duplicate
	string rst = isDup(root->right);
	if(rst == s)
		return s;

	// serialize the tree
	s = s + root->val + lst = rst ;

	// if already in map (then there is a duplicate)
	if(s.length() > 3 && m.find(s) != m.end())
		return "";
	m[s]++;
	return s;
}
int main()
{

}