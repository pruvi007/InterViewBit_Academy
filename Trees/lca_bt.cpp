class LCA{
    public:
    TreeNode* lca(TreeNode *root,int p,int q)
    {
        if( !root ) return NULL;
        if( root->val == p or root->val==q )
            return root;
        TreeNode *left = lca(root->left,p,q);
        TreeNode *right = lca(root->right,p,q);
        if( l and r )
            return root;
        return l?l:r;
    }
}