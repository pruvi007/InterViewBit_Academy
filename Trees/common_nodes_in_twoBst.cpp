/*
	Find common nodes in two BST's
	1. do the inorder and find them->O(n) space
	2. can we do better.. yes we can use O(h) space
	Do iterative inorder and them match the stack tops with each other.
*/
// solution by @pruvi007

#define ll long long int
ll inorder(TreeNode *A,TreeNode *B)
{
    stack<TreeNode *> s1,s2;
    TreeNode *cur1=A,*cur2=B;
    ll sum = 0;
    while(1)
    {
        if(cur1)
        {
            s1.push(cur1);
            cur1 = cur1->left;
        }
        else if(cur2)
        {
            s2.push(cur2);
            cur2 = cur2->left;
        }
        else if(!s1.empty() && !s2.empty())
        {
            cur1 = s1.top();
            cur2 = s2.top();
            if(cur1->val == cur2->val)
            {
                sum += cur1->val;
                s1.pop();
                s2.pop();
                cur1 = cur1->right;
                cur2 = cur2->right;
            }
            else if(cur1->val > cur2->val)
            {
                s2.pop();
                cur2 = cur2->right;
                cur1 = NULL;
            }
            else
            {
                s1.pop();
                cur1 = cur1->right;
                cur2 = NULL;
            }
        }
        else break;
    }
    return sum;
}
int Solution::solve(TreeNode* A, TreeNode* B) {
    return inorder(A,B);
    
}