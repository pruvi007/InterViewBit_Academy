#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int t;
	cin >> t;
	for(int z=1;z<=t;z++)
	{
		ll n;
		cin >> n;
		ll a[n];
		ll dp[n]={0};
		for(int i=0;i<n;i++)
			cin >> a[i];
		dp[0] = a[0];
		if(n==0)
			cout << "Case " << z <<": " << 0 << endl;
		else if(n==1)
			cout << "Case " << z <<": " << dp[0] << endl;
		else
		{
			dp[1] = max(a[0],a[1]);
			for(int i=2;i<n;i++)
				dp[i] = max( dp[i-1],a[i]+dp[i-2] );
			cout << "Case " << z <<": " << dp[n-1] << endl;
		}
	}
}