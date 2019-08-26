/*find sum of all differences of Max and min element over all subsets*/
//solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

/* approach: sort the array. a1 will be min for all subsets formed by (a2,a3,..an) so contribution of a1 is 2^(n-1). Now 
generalise */

#define ll long long int
ll mod = 1e9+7;

ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll x = power(a,b/2);
	if(b%2==0)
	{
		return (x%mod*x%mod)%mod;
	}
	else
	{
		return (x%mod * (x%mod*a%mod)%mod)%mod;
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ll M = 0,m=0;
	for(int i=0;i<n;i++)
	{
		ll p = power(2,n-i-1);
		M = (M + (a[i]%mod*p%mod)%mod )%mod;
		m = (m + (a[n-i-1]%mod*p%mod)%mod )%mod;
	}
	cout<<abs(M - m)<<endl;
}