/*
	CALVIN's GAME
	make the array continuos and derive the linear recurrence
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	int n,k;
	cin >> n >> k;
	vector<ll> v;
	ll a[n];
	for(int i=0;i<n;i++)
	{
		ll x;
		cin >> x;
		v.push_back(x);
		a[i] = x;
	}
	for(int i=n-2;i>=0;i--)
	{
		v.push_back(a[i]);
	}

	ll dp[2*n+1];
	dp[k-1] = 0;
	dp[k] = max(dp[k-1],v[k]);
	for(int i=k+1;i<2*n-1;i++)
	{
		dp[i] = max(dp[i-1]+v[i],dp[i-2]+v[i]);
	}
	// dp[2*n-2] = dp[2*n-3] + v[0];
	for(int i=0;i<2*n-1;i++)
		cout << v[i] << " ";
	cout << endl;
	for(int i=k-1;i<2*n-1;i++)
		cout << dp[i] << " ";
	cout << endl;
	cout << dp[2*n-2] << endl;
}