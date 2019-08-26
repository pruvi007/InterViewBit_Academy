/*
	Gold Miner->move diagonally up and diagonally down
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int a[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin >> a[i][j];
		int dp[n][m];
		dp[0][0] = a[0][0];
		if( n==1 )
		{
			int sum = 0;
			for(int i=0;i<m;i++)
				sum += a[0][i];
			cout << sum << endl;
			continue;
		}

		for(int i=1;i<n;i++)
			dp[i][0] =  a[i][0];

		for(int j=1;j<m;j++)
		{
			for(int i=0;i<n;i++)
			{
				
				if( i==n-1 )
				{
					dp[i][j] = a[i][j] + max( dp[i][j-1],dp[i-1][j-1] );
				}
				else if( i==0 )
				{
					dp[i][j] = a[i][j] + max( dp[i][j-1],dp[i+1][j-1] );
				}
				else
					dp[i][j] = a[i][j] + max( dp[i][j-1], max( dp[i-1][j-1],dp[i+1][j-1] ) );
			}
		}
		// cout << endl;
		// for(int i=0;i<n;i++)
		// {
		// 	for(int j=0;j<m;j++)
		// 		cout << dp[i][j] << " ";
		// 	cout << endl;
		// }
		int ans = INT_MIN;
		for(int i=0;i<n;i++)
			ans = max(ans, dp[i][m-1]);
		cout << ans << endl;
	}
}