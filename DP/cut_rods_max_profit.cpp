/*
	cut rods such that you gain max profit

*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

map<int,int> m;
int cutRods(vector<int> &a,int n)
{
	if(n<=0)
		return 0;
	
	int cMax = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(m.find(n-i-1) != m.end())
			cMax = max(cMax,a[i]+m[n-i-1]);
		else
		{
			cMax = max(cMax,a[i]+cutRods(a,n-i-1));
			m[n] = cMax;
		}
		
	}
	return cMax;
}

int cutRodsT(vector<int> &a,int n)
{
	int dp[n+1];
	dp[0] = 0;
	for(int i=1;i<=n;i++)
	{
		int cMax = INT_MIN;
		for(int j=0;j<i;j++)
			cMax = max(cMax,a[j]+dp[i-j-1]);
		dp[i] = cMax;
	}
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	m.clear();
	int ans = cutRods(a,n);
	cout << ans << endl;
	cout << cutRodsT(a,n) << endl;
}