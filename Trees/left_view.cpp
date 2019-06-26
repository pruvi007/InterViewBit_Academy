/*
    print the left view of the tree
    Implementation using queue
*/
// solution by @pruvi007

vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(A);
    while(!q.empty())
    {
        int n = q.size();
        ans.push_back(q.front()->val);
        for(int i=0;i<n;i++)
        {
            TreeNode *t = q.front();
            q.pop();
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
    }
    return ans;
}
