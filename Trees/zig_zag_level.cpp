/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    /*
        idea is to use a queue. and push elements of each level by considering size of previous level.
    */
    queue<TreeNode *> q;
    q.push(A);
    int idx = 0;
    vector<vector<int> > f;
    while(q.size()>0)
    {
        // till n we will pop and push each node's left and right
        int n = q.size();
        vector<int> ans;
        queue<TreeNode *> temp = q;
        while(temp.size()>0)
        {
            ans.push_back(temp.front()->val);
            temp.pop();
        }

        // remove this step to get the simple level order traversal
        if(idx%2!=0)
            reverse(ans.begin(),ans.end());
        
        f.push_back(ans);
        for(int i=0;i<n;i++)
        {
            TreeNode *n = q.front();
            q.pop();
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        idx++;
        
    }
    return f;
}
