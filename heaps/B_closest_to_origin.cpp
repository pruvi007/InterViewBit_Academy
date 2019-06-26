/*
	Find B closest points to orgin
	Idea: use a min heap to store triplets 
*/
// solution by @pruvi007

struct point{
	int d;
	int x;
	int y;
	point(int sum,int i,int j)
	{
		this->d = sum;
		this->x = i;
		this->y = j;
	}
};

struct myComp{
	bool operator()(point *a,point *b)
	{
		return a->sum > b->sum;
	}
};


vector<vector<int> > Solution::solve(vector<vector<int> > &a, int k) {
	vector<vector<int> > v;
	priority_queue< point,vector<point>,myComp > pq;
	int n = a.size();
	for(int i=0;i<n;i++)
	{
		int x = a[i][0];
		int y = a[i][1];
		int sum = x*x + y*y;
		pq.push(point(sum,x,y));
	}

	vector<int> temp;
	for(int i=0;i<k;i++)
	{
		point *p = pq.top();
		pq.pop();
		
		temp.clear();
		temp.push_back(p->x);
		temp.push_back(p->y);
		v.push_back(temp);
	}
	return v;
}