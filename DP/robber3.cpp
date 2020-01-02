/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Following method follows the same idea as the HouseRobber 1
1. if you rob root -> choice to rob the 4 grandchildren ( root.left.left,root.left.right ..... )
2. if you dont rob the root -> choice to rob the children (root.left,root.right)
*/
 map<TreeNode*,int> mp;
 int solve(TreeNode *root)
 {
     if(mp.find(root)!=mp.end())
         return mp[root];
     if(root==NULL)
         return 0;

     // val contains the sum of 4 grandchildren
     int val = 0;
     if(root->left)
         val += solve(root->left->left) + solve(root->left->right);
     if(root->right)
         val += solve(root->right->left) + solve(root->right->right);
     // max of 1st case and 2nd case
     mp[root] = max( val+root->val,solve(root->left)+solve(root->right) );
     return mp[root];
 }


class Solution {
public:
    int rob(TreeNode* root) {
      return solve(root);
    }
};
