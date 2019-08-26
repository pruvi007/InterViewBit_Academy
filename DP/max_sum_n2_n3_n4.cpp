/*
	Given n , find the max sum by breaking n into n/4,n/3,n2 recursively
	find the max out of (n/2+n/3+n/4 and n) (recursively)
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll M = 0;
ll maxSum(ll n)
{
	if( n==0 || n==1 )
		return n;
	
	ll res = max( maxSum(n/2)+maxSum(n/3)+maxSum(n/4), n );
	return res;
}

ll maxSumTable( ll n )
{
	ll dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2;i<=n;i++)
	{
		dp[i] = max( dp[i/2]+dp[i/3]+dp[i/4], (ll)i );
	}
	return dp[n];
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll ans = maxSum(n);
		cout << ans << endl;
		ans = maxSumTable(n);
		cout << ans << endl;
	}
}