/*
	MAXIMUM SUM
	max sum A[i]*A[j]*A[k]
	idea: create a n*3 dp table-> 0 column will store max of X*A[i]
	1 column will store max of column 0 + Y*A[i] and previous column 1
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	int x,y,z;
	cin >> x >> y >> z;
	int dp[n][3];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
			dp[i][j] = INT_MIN;
	}

	for(int i=0;i<n;i++)
	{
		// build the 0th column
		if(i==0)
		{
			dp[i][0] = x*a[i];
		}
		else
		{
			dp[i][0] = max(dp[i-1][0],x*a[i]);
		}
		
	}
	for(int i=0;i<n;i++)
	{
		// build the 1st column
		if(i==0)
		{
			dp[i][1] = dp[i][0] + y*a[i];
		}
		else
		{
			dp[i][1] = max(dp[i-1][1],dp[i][0]+y*a[i]);
		}
		
	}
	for(int i=0;i<n;i++)
	{
		// build the 2nd column
		if(i==0)
		{
			dp[i][2] = dp[i][1] + z*a[i];
		}
		else
		{
			dp[i][2] = max(dp[i-1][2],dp[i][1]+z*a[i]);
		}
		
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	cout << dp[n-1][2] << endl;

}