/*
	SHIP
	FInd the min and max cost of tickets
	idea: use heaps to get the required
*/
vector<int> Solution::solve(int A, int B, vector<int> &a) {
    // MAX HEAP to get max
    priority_queue<int> M;
    // MIN HEAP
    priority_queue<int,vector<int>,greater<int> > m;
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        M.push(a[i]);
        m.push(a[i]);
    }
    int max = 0;
    for(int i=0;i<A;i++)
    {
        int x = M.top();
        max += x;
        M.pop();
        if(x-1 > 0)
            M.push(x-1);
    }
    int min = 0;
    for(int i=0;i<A;i++)
    {
        int x = m.top();
        min += x;
        m.pop();
        if(x-1 > 0)
            m.push(x-1);
    }
    vector<int> ans;
    ans.push_back(max);
    ans.push_back(min);
    return ans;
}
