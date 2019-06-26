/*
	Find kth largest element in a stream of elements
	i.e kth largest in subarrays [1,1],[1,2],[1,3].....[1,n]
	idea: to use a k sized min-heap which will contain the kth largest in O(1) time.
	if a[i]>top() then replace min
	else print top
*/
// solution by @pruvi007

vector<int> Solution::solve(int k, vector<int> &B) {
    priority_queue<int,vector<int>, greater<int> > pq;
    priority_queue<int,vector<int>, greater<int> > temp;
    int n = B.size();
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        pq.push(B[i]);
        if(i<k-1)
            ans.push_back(-1);
    }
    ans.push_back(pq.top());
    for(int i=k;i<n;i++)
    {
        
        if(B[i]>pq.top())
        {
            pq.pop();
            pq.push(B[i]);
        }
        ans.push_back(pq.top());
    }
    return ans;
}

