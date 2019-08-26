#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin >> a[i][j];
		

		int dp1[n][n];
		dp1[0][0] = a[0][0];
		for(int i=1;i<n;i++)
			dp1[0][i] = dp1[0][i-1] + a[0][i];
		for(int i=1;i<n;i++)
			dp1[1][i] = dp1[1][i-1]+a[1][i];
		for(int i=1;i<n-1;i++)
			dp1[i][i] = INT_MAX;
		for(int i=1;i<n;i++)
		{
			for(int j=2;j<n;j++)
			{
				if(j>i)
					dp1[i][j] = min(dp1[i-1][j],dp1[i][j-1]) + a[i][j];
				else dp1[i][j] = INT_MAX;
				
			}
		}
		int top = dp1[n-2][n-1] + a[n-1][n-1];
		// cout << dp1[n-2][n-1] + a[n-1][n-1] << endl;

		dp1[n-1][n-1] = a[n-1][n-1];
		for(int i=n-2;i>=0;i--)
			dp1[n-1][i] = dp1[n-1][i+1] + a[n-1][i];
		for(int i=n-2;i>=0;i--)
			dp1[i][n-2] = dp1[i+1][n-2] + a[i][n-2];
		 for(int i=1;i<n-1;i++)
			dp1[i][i] = INT_MAX;
		for(int i=n-2;i>=0;i--)
		{
			for(int j=n-3;j>=0;j--)
			{
				if(i>j)
					dp1[i][j] = min(dp1[i+1][j],dp1[i][j+1]) + a[i][j];
				else dp1[i][j] = INT_MAX;
			}
		}
		int low = a[0][0] + dp1[1][0];
		// cout << top << " " << low << endl;
		cout << top+low-a[n-1][n-1] << endl; 


	}
}