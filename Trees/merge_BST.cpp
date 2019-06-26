/*
	given two BST's
	Merge the two and get the final inorder
	Do it in O(h(a) + h(b)) space.
*/
// solution by @pruvi007

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> ans;

void inorder(TreeNode *A,TreeNode *B)
{
	stack<TreeNode *> s1,s2;
	TreeNode *c1=A,*c2=B;
	int l=1,r=1;
	while(1)
	{
	    
        while(c1)
		{
			s1.push(c1);
			c1 = c1->left;
		}
		while(c2)
		{
			s2.push(c2);
			c2 = c2->left;
		}
	    
	    
		

		if(!s1.empty() && !s2.empty())
		{
			c1 = s1.top();
			c2 = s2.top();
			if(c1->val < c2->val)
			{
				ans.push_back(c1->val);
				s1.pop();
				c1 = c1->right;
				c2=NULL;
				
			}
			else if(c1->val > c2->val)
			{
				ans.push_back(c2->val);
				s2.pop();
				c2 = c2->right;
				c1=NULL;
				
			}
			else
			{
				ans.push_back(c1->val);
				ans.push_back(c2->val);
				s1.pop();
				s2.pop();
				c1 = c1->right;
				c2 = c2->right;
				
			}
		}
		else break;
	}
    if(!s1.empty())
    {
        c1=NULL;
        while(c1 || !s1.empty())
        {
             while(c1)
            {
                s1.push(c1);
                c1 = c1->left;
            }
            c1 = s1.top();
            s1.pop();
            ans.push_back(c1->val);
            c1 = c1->right;
        }
       
    }
    if(!s2.empty())
    {
        c2=NULL;
        while(c2 || !s2.empty())
        {
            while(c2)
            {
                s2.push(c2);
                c2 = c2->left;
            }
            c2 = s2.top();
            s2.pop();
            ans.push_back(c2->val);
            c2 = c2->right;
        }
       
    }
    
	

	
}
vector<int> Solution::solve(TreeNode* A, TreeNode* B) {
    ans.clear();
    inorder(A,B);
    return ans;
}
