/*
	MIN JUMPS ARRAY
	Find the min no. of jumps to reach the end.
	(from any point you can reach to any point till a[i])

	idea: use recurrence relation and then Memoization
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> m;
int minJumps(vector<int> &a,int s,int e)
{
	if(s==e)
		return 0;
	if(a[s] == 0)
		return INT_MAX;

	int cMin = INT_MAX;
	for(int i=s+1;i<=e && i<=s+a[s];i++)
	{
		int jumps;
		if(m.find({i,e})!=m.end())
			jumps = m[{i,e}];
		
		else
			jumps = minJumps(a,i,e);
			
		
		if(jumps != INT_MAX && jumps+1 < cMin)
		{
			cMin = jumps+1;
			m[{i,e}] = cMin;
		}

	}
	return cMin;
}
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	int ans = minJumps(a,0,n-1);
	cout << ans << endl;
}