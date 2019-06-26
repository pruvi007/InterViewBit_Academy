/*
	help TA
	use max heap with triplet and a modified comparator
*/
// solution by @pruvi007

struct stu{
	int doubt;
	int roll;
	stu(int d,int r)
	{
		this->doubt = d;
		this->roll = r;
	}
};

struct myComp{
	bool operator()(stu a,stu b)
	{
		// max doubts and min roll no.
		return ( (a.doubt<b.doubt) || ((a.doubt==b.doubt) && (a.roll>b.roll)) );
	}
};

vector<int> Solution::solve(vector<int> &a, int k) {
	priority_queue<stu,vector<stu>,myComp> pq;
	for(int i=0;i<a.size();i++)
	{
		pq.push(stu(a[i],i));
	}
	vector<int> ans;
	for(int i=0;i<k;i++)
	{
		stu x = pq.top();
		if(x.doubt==0)
		    break;
		ans.push_back(x.roll);
		pq.pop();
		int d = x.doubt;
		
		pq.push(stu(d-1,x.roll));
	}
	return ans;
}
