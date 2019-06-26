/*
	sum of all odd levels - sum of all even levels
	can do it by level order
	but by recursion its just one line
*/
// solution by @pruvi007

#define ll long long int
ll diff(TreeNode *root)
{
	if(root==NULL)
		return 0;
	// carefully notice how the signs of level is tracked by the exprssion below
	return root->val - diff(root->left) - diff(root->right);
}
int Solution::solve(TreeNode* A) {
    ll ans = diff(A);
    return ans;
}