int ans=0;
int unival(TreeNode *root)
{
    if(root == NULL)
        return 0;
    int lval=unival(root->left),rval=unival(root->right);
    int lr=0,rr=0;
    if( root->left and root->val == root->left->val )
        lr = 1+lval;
        
    if(root->right and root->val==root->right->val )
        rr = 1+rval;
    
    ans = max(ans,lr+rr);
        
    return max(lr,rr); 
    
}
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        ans=0;
        int x = unival(root);
        return ans;
        
    }
};