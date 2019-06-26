/*
	minmize the final sum obtained by adding the number itself.
	use min heap with an advacned comparator.
*/
// solution by @pruvi007

struct node{
	int cur;
	int act;
	node(int cur,int act)
	{
		this->cur = cur;
		this->act = act;
	}
};


// awesome comparator.
struct myComp{
	bool operator()(node a,node b)
	{
	   // tricky comparator
	   // first compare the if next sum is lesser or not. If same then check for their actual sums
		return ( (a.cur+a.act > b.cur+b.act) || (a.cur==b.cur && a.act > b.act) );
	}
};

int Solution::solve(vector<int> &a, int k) {
	int n = a.size();
	priority_queue< node,vector<node>,myComp > pq;
	for(int i=0;i<n;i++)
	{
		pq.push(node(a[i],a[i]));
	}
	
	for(int i=0;i<k;i++)
	{
		node x = pq.top();
		pq.pop();
		pq.push(node(x.cur+x.act,x.act));
	}
	int max = INT_MIN;
	while(!pq.empty())
	{
	    if(pq.top().cur>max)
	        max = pq.top().cur;
	   pq.pop();
	}
	return max;
}
