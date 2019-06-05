/*
	Check whether two trees are symmetric
	Two trees are symmetric if mirror image is same as the given tree.

	idea is to recusively check root->left and root->right values .. if they are equal then ok else not

	or

	generate inorder of the mirror tree by swapping i and n-i positions
	then genrate mirror and check thr corresponding inorders.
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node *left,*right;
	node(int data)
	{
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};

int isSymmetric(node *root1,node *root2)
{
	if(root1 == NULL && root2==NULL)
		return 1;
	if(root1 && root2 && root1->val == root2->val)
	{
		return isSymmetric(root1->left,root2->right) && isSymmetric(root1->right,root2->left);
	}

	return 0;
	
}
vector<int> in1,in2;
void inorder(node *root)
{
	stack<node *> s;
	s.push(root);
	while(!s.empty())
	{
		while(root->left)
		{
			s.push(root->left);
			root = root->left;
		}
		root = s.top();
		in1.push_back(root->val);
		s.pop();
		if(root->right)
		{
			root = root->right;
			s.push(root);
		}
		
	}
}
void mirror(node *root)
{
	if(root == NULL)
		return ;
	mirror(root->left);
	mirror(root->right);

	node *temp = root->left;
	root->left = root->right;
	root->right = temp;
}
int main()
{
	node *root        = new node(1); 
    root->left        = new node(2); 
    root->right       = new node(2); 
    root->left->left  = new node(3); 
    root->left->right = new node(4); 
    root->right->left  = new node(4); 
    root->right->right = new node(3); 

    int ans = isSymmetric(root,root);
    cout<<ans<<endl;
    inorder(root);
    cout<<endl;
    for(int i=0;i<in1.size()/2;i++)
    {
    	int t = in1[i];
    	in1[i]= in1[in1.size()-i-1];
    	in1[in1.size()-i-1] = t;
    }
    in2 = in1;
    in1.clear();
    mirror(root);
    inorder(root);
    cout<<endl;

    for(int i=0;i<in2.size();i++)
    	cout<<in2[i]<<" ";
    cout<<endl;
    for(int i=0;i<in1.size();i++)
    	cout<<in1[i]<<" ";
    cout<<endl;
}