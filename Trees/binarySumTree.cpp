/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int l=0,r=0;
bool sum(TreeNode *root)
{
    if(root==NULL)
        return true;
    sum(root->left);
    sum(root->right);

    // if its leaf then return true
    if(!root->left and !root->right)
        return true;

    // maintain left subtree and right subtree sums separately 
    // so that no additional time is required to compute the sums
    l += root->left?root->left->val:0;
    r += root->right?root->right->val:0;
    // cout << root->val << " " << l << "  " << r << endl;
    if(l+r==root->val)
        return true;
    return false;
}
int Solution::solve(TreeNode* A) {
    l=0;r=0;
    return sum(A);
}
