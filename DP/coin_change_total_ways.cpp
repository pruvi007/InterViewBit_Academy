/*
	Count total ways to make the given sum with infinite supply of coins
	recu: include ith coin + exclude ith coin
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int totalWays(vector<int> &a,int n,int s)
{
	if(s==0)
		return 1;
	if(s<0)
		return 0;
	if(n<=0 && s>0)
		return 0;
	return totalWays(a,n-1,s) + totalWays(a,n,s-a[n-1]);
}

int table(vector<int> &a,int s)
{
	int n = a.size();
	int dp[s+1]={0};
	dp[0] = 1;
	for(int i=0;i<n;i++)
	{
		// update all the values smaller than sum
		for(int j=a[i];j<=s;j++)
			dp[j] = dp[j] + dp[j-a[i]];
	}
	return dp[s];
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
	int sum;
	cin >> sum;
	int ans = totalWays(a,n,sum);
	cout << ans << endl;
	cout << table(a,sum) << endl;
}