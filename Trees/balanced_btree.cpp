/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int bal_tree(TreeNode *A)
{
    if(A==NULL)
        return 0;
    int a = bal_tree(A->left);
    int b = bal_tree(A->right);
    
    if(abs(a-b)>1)
        return -1;
        
    // the following will be achieved because of above call.
    if(a<0 || b<0)
        return -1;
        
    if(abs(a-b)<=1)
        return max(a,b)+1;
    else
        return 1;
}
int Solution::isBalanced(TreeNode* A) {
    int h = bal_tree(A);
    if(h<0)
        return 0;
    return 1;
}
