/*
	Count total paths in a grid
	obstacles can be there
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int a[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];

	int dp[n][m];
	dp[0][0] = 1;
	int f=0;
	for(int i=1;i<m;i++)
	{
	    if(a[0][i]==1)
	    {
	        dp[0][i]=0;
	        f=1;
	    }
	    if(f==1)
	        dp[0][i]=0;
	    else
	        dp[0][i] = 1;
	}
	f=0;
	for(int i=1;i<n;i++)
	{
	    if(a[i][0]==1)
	    {
	        dp[i][0]=0;
	        f=1;
	    }
	    if(f==1)
	        dp[i][0] = 0;
	    else
	        dp[i][0] = 1;
	}
		
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(a[i][j]==0)
			{
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
			else
				dp[i][j] = 0;
		}
	}

	cout << dp[n-1][m-1] << endl;
}