/*
	if height of tree is h then we will have 2^(h-1) nodes + nodes in the hth level
	task is to efficiently calculate the last level nodes
	(use binary search to get them (T T T T  F F F F F F) binary will return true on last )
	use 0 1 tree representation

*/

#include<bits/stdc++.h>
using namespace std;

bool isNodePresent(TreeNode *A,int x,int h)
{
	vector<bool> a;
	int X = x;
	while(x)
	{
		a.push_back(x%2);
		x = x/2;
	}
	reverse(a.begin(),a.end());
	int rem = h - a.size();
	vector<bool> a2;
	for(int i=0;i<rem;i++)
	    a2.push_back(0);
	for(int i=0;i<a.size();i++)
	    a2.push_back(a[i]);
	cout << X << ": ";
	for(int i=0;i<a2.size();i++)
	    cout << a2[i] << " ";
	cout << endl;
	
	TreeNode *temp = A;
	for(int i=0;i<a2.size();i++)
	{
		if(a2[i]==true)
			temp = temp->right;
		else
			temp = temp->left;
		if(temp == NULL)
		    break;
		
	}
// 	cout << temp->val << "\n";
	return temp != NULL;
}
int Solution::solve(TreeNode* A) {
    int h = 0;
    TreeNode *temp = A;
    int nodes = 0;
    while(temp->left)
    {
        nodes += pow(2,h);
    	h++;
    	temp = temp->left;
    }
    
    int low = 0,high = pow(2,h)-1;
    int ans = -1;
    while(low<=high)
    {
    	int mid = (low+high)/2;
    	bool valid = isNodePresent(A,mid,h);
    	if(valid)
    	{
    		ans = mid;
    		low = mid+1;
    	}
    	else
    		high = mid-1;

    }
    // cout << nodes << " " << ans << endl;
    return nodes + ans +1;
}