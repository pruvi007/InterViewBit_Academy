/*
	ROBBING Houses
	You need to rob house but if you rob house i you cant rob its adjcent house
	idea: to build the recurrence relation as 
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

// to remove the redundancy use memoization
map<int,int> m;
int robHouse(vector<int> &a,int s,int e)
{
	if(s==e)
		return a[s];
	if(s>e)
		return 0;
	int cMax = INT_MIN;
	if(m.find(s+2) != m.end() && m.find(s+1) != m.end())
	{
		cMax = max(a[s]+m[s+2],m[s+1]);
	}
	else if(m.find(s+2)==m.end() && m.find(s+1)!=m.end())
	{
		cMax =  max(a[s]+robHouse(a,s+2,e),m[s+1]);
		m[s] = cMax;
	}
	else if(m.find(s+2)!=m.end() && m.find(s+1)==m.end())
	{
		cMax = max(a[s]+m[s+2],robHouse(a,s+1,e));
		m[s] = cMax;
	}
	else
	{
		cMax = max(a[s]+robHouse(a,s+2,e),robHouse(a,s+1,e));
		m[s] = cMax;
	}
	return cMax;

	
}

// tabular approach (bottom up (very fast) but not quite intuitive)
int robHouseTab(vector<int> &a)
{
   // runtime on LEETCode is 0ms (100% beaten yoooooo..... )
	int n = a.size();
	 if(n==0)
	    return 0;
	if(n==1)
	    return a[0];
	if(n==2)
	    return max(a[0],a[1]);
	int dp[n];
	dp[0] = a[0];
	dp[1] = max(a[0],a[1]);

	for(int i=2;i<n;i++)
	{
	    dp[i] = max(dp[i-1],a[i]+dp[i-2]);
	}
	return dp[n-1];

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
	int rob = robHouse(a,0,n-1);
	int robT = robHouseTab(a);
	cout << rob << endl;
	cout << robT << endl;
}