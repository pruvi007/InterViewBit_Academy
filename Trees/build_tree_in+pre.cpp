/*
	build tree from inorder and preorder.
	idea is to pick an element from pre and search in inorder to get left and right subtrees
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

struct node {
	int val;
	node *left,*right;
	node(int data)
	{
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};


int find(int in[],int st,int x,int n)
{
	for(int i=st;i<=n;i++)
	{
		if(in[i]==x)
			return i;
	}
	return -1;
}
node *build(int in[],int pre[],int left,int right)
{
	static int root = 0;
	if(right<left)
		return NULL;

	node *n = new node(pre[root]);
	root++;
	if(left == right)
		return n;

	int pos = find(in,left,n->val,right);
	node *lst = build(in,pre,left,pos-1);
	node *rst = build(in,pre,pos+1,right);
	n->left = lst;
	n->right = rst;

	return n;
}

void inorder(node *node)
{
	if (node == NULL)  
        return;  
  
    /* first recur on left child */
    inorder(node->left);  
  
    /* then print the data of node */
    cout<<node->val<<" ";  
  
    /* now recur on right child */
    inorder(node->right);  
}
int main()
{
	/*

			1
	       /   \
	     /       \
	    2         3
	   / \        /
	 /     \    /
	4       5  6

	inorder = 4 2 5 1 6 3

*/
	int in[] = { 4, 2, 5, 1, 6, 3 };  
    int pre[] = { 1, 2, 4, 5, 3, 6 };  
    int len = sizeof(in) / sizeof(in[0]);  
    node* root = build(in, pre, 0, len - 1);  
  
    /* Let us test the built tree by  
    printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";  
    inorder(root);
    cout<<endl;
}





// IB solution with hashmap O(1) search so total complexity is O(n)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*map<int,int> m;
int index(vector<int> &inorder, int val, int start, int end){
    int i;
    for(i = start; i <= end; i++){
        if(inorder[i] == val){
            return i;
        }
    }
    return -1;
} 

TreeNode* make(vector<int> &preorder, vector<int> &inorder, int start, int end, int &preInd){
    if(start > end){
        return NULL;
    }
    
    TreeNode* root = new TreeNode(preorder[preInd]);
    preInd++;
    
    if(start == end){
        return root;
    }
    
    int ind = m[root->val];
    
    root->left = make(preorder, inorder, start, ind-1, preInd);
    root->right = make(preorder, inorder, ind+1, end, preInd);
    
    return root;
} 
 
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    m.clear();
    int n = inorder.size();
    for(int i=0;i<n;i++)
        m[inorder[i]] = i;
    int pre = 0;
    return make(preorder, inorder, 0, preorder.size()-1, pre);
    
}