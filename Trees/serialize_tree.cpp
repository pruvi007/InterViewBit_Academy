/*
	Serialize the given tree
	Means
	Convert the string into string format
	To store the tree in a file we use tree serialization
	 20
    /   \
   8     22 
	Ser_tree = 20 8 -1 -1 22 -1 -1 
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
string s = "";
char marker = '#';
void serialize(node *root)
{
	if(root==NULL)
	{
		s = s+" "+marker+" ";
		return ;
	}
	s = s + to_string(root->val)+" ";

	serialize(root->left);
	serialize(root->right);

}
int main()
{
	node *root               = new node(20); 
    root->left               = new node(8); 
    root->right              = new node(22); 
    root->left->left         = new node(4); 
    root->left->right        = new node(12); 
    root->left->right->left  = new node(10); 
    root->left->right->right = new node(14); 
    s = "";
    serialize(root);
    cout<<s<<endl;
}
