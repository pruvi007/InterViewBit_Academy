/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> > v;
    if(A==NULL)
        return v;
    

    /*
        idea: create a queue. push root with d=0
        pop q.front and push left child with d-1 and right child with d+1
        store the values in map<int,vector<>> 
    */
    queue<pair<TreeNode *,int> > q;
    q.push({A,0});
    map<int,vector<TreeNode *> > m;
    while(q.size()>0)
    {
        pair<TreeNode *,int> p = q.front();
        q.pop();
        m[p.second].push_back(p.first);
        if(p.first->left)
            q.push({p.first->left,p.second-1});
        if(p.first->right)
            q.push({p.first->right,p.second+1});
        
    }
    
    map<int,vector<TreeNode *> >::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        vector<TreeNode *> temp = it->second;
        vector<int> t;
        for(int i=0;i<temp.size();i++)
        {
            t.push_back(temp[i]->val);
        }
        v.push_back(t);
    }
    return v;
}
