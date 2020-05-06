#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	double dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	/*
		dp[i][j]- i heads from first j coins
		case head - i-1 heads from j-1 coins
		case tail - i heads from j-1 coins
	*/
	dp[0][0] = 1.0;
	for(int i=1;i<=n;i++)
		dp[0][i] = (1-a[i-1])*dp[0][i-1];
	for(int i=1;i<=n;i++)
	{
		for(int heads=1;heads<=i;heads++)
		{
			dp[heads][i] = a[i-1]*dp[heads-1][i-1] + (1-a[i-1])*dp[heads][i-1];
		}
	}
	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=n;j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	double ans = 0.0;
	for(int i=n/2+1;i<=n;i++)
		ans += dp[i][n];
	cout << setprecision(9) << ans << endl;
}