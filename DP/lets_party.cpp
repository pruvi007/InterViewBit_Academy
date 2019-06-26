/*
	In a party you can enjoy either by single or in a pair
	Find the number of ways to enjoy the party
	idea: if consider single or choose n-1 and enjoy double
	f(i-1) + (n-1)F[i-2]
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

map<int,int> m;
int party(int n)
{
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	// you can choose a partner from n-1 people
	return party(n-1) + (n-1)*party(n-2);
}
int partT(int n)
{
	int dp[n+1];
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=n;i++)
		dp[i] = dp[i-1]%mod + ((i-1)%mod*dp[i-2]%mod)%mod;
	return dp[n]%mod;
}
int main()
{
	int n;
	cin>>n;
	int ans = party(n);
	cout << ans << endl;
	cout << partT(n) << endl;
}