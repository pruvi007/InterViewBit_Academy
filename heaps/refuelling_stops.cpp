/*
	find the minimum number of refuelling stops to reach the destinations.
	idea: let the vehilcle go to the part till fuel is there. If not the destination then he hould have taken the max fuel on the way. 
	So maintain a heap of fuels that has not been taken yet.

	A = 100
    B = 10
    C = [10, 20, 30, 60]
    D = [60, 30, 30, 40]
*/
// solution by @pruvi007

int Solution::solve(int dest, int st, vector<int> &miles, vector<int> &fuel) {
	priority_queue<int> pq;
	int n = miles.size();
	int sum = 0;
	int c = 0;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			if(st-miles[i] >=0 )
			{
				st -= miles[i];
				sum+=miles[i];
				
				if(sum>=dest)
					break;
				pq.push(fuel[i]);
			}
			else
				return -1;
		}
		else
		{
			if((st-abs(miles[i-1]-miles[i])) >=0 )
			{
				st-=abs(miles[i-1]-miles[i]);
				sum+=abs(miles[i-1]-miles[i]);
				
				if(sum>=dest)
					break;
				pq.push(fuel[i]);
			}
			else if((st-abs(miles[i-1]-miles[i]))<0 && sum<dest)
			{
				st+=pq.top();
				pq.pop();
				c++;
				st-=abs(miles[i-1]-miles[i]);
				sum+=abs(miles[i-1]-miles[i]);
				pq.push(fuel[i]);
			}
		}
		
	}
	sum += st;
	if(sum<dest)
	{
		while(!pq.empty())
		{
			sum += pq.top();
			c++;
			pq.pop();
			if(sum>=dest)
				break;
		}
	}
	return c;

}
