/*
	find number of nodes in a bst that lie within [l,r]
	approach: if root lies between traverse both side
	else either of one sides
*/
// solution by @pruvi007

int c = 0;
void range(TreeNode *root,int l,int r)
{
	if(root==NULL)
		return;
	if(root->val >=l && root->val<=r)
	{
		// check both sides and increment 1
		c++;
		range(root->left,l,r);
		range(root->right,l,r);
	}
	else if(root->val >l && root->val>r)
	{
		// goto left
		range(root->left,l,r);
	}
	else{
		// goto right
		range(root->right,l,r);
	}
}
int Solution::solve(TreeNode* A, int B, int C) {
    c=0;
    range(A,B,C);
    return c;
}