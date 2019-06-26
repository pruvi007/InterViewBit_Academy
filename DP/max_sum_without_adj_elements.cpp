/*
	given 2*n elements find the max sum by taking elements which are not adjacent (not V,H,D)
	idea: in a column choose greedily (because both will give the same scenario of elements that are nto chosen)
	then it resuces to robbing house problem
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

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
	int a[2][n];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	vector<int> p;
	for(int i=0;i<n;i++)
	{
		int x = a[0][i];
		int y = a[1][i];
		p.push_back(max(x,y));
	}

	int ans = robHouseTab(p);
	cout << ans << endl;

}