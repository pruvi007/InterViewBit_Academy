/*
	substring diff at HR
	idea: store a dp array which gives the info about mismatched chars from i to j of s1 and s2
	then apply binary search
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int k;
		cin >> k;
		string s1,s2;
		cin >> s1 >> s2;
		int n = s1.length();

		// build the dp array that would store no. of mismatched chars from i-j
		int dp[n][n];
		for(int i=0;i<n;i++)
		{
			if(s1[i] == s2[i])
				dp[i][i] = 0;
			else dp[i][i] = 1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(s1[j] == s2[j])
					dp[i][j] = dp[i][j-1];
				else
					dp[i][j] = dp[i][j-1]+1;
			}
		}
		// for(int i=0;i<n;i++)
		// {
		// 	for(int j=0;j<i;j++)
		// 		cout << "-1 ";
		// 	for(int j=i;j<n;j++)
		// 	{
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		// now start the BS to get the longest substring
		int low = k,high=n;
		int ans = -1;
		while(low <= high)
		{
			int mid = (low + high)/2;

			// find if any interval is having less than k
			int valid = 0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(j>=i && (1+abs(i-j))== mid)
					{
						if(dp[i][j] <= k)
						{
							valid = 1;
							break;
						}
						
					}
				}
				if(valid)
					break;
			}

			if(valid)
			{
				ans = mid;
				low = mid+1;
			}
			else high = mid-1;
		}

		cout << ans << endl;

		for(int z=n;z>=0;z--)
		{
			int valid = 0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(j>=i && (1+abs(i-j))== z)
					{
						if(dp[i][j] <= k)
						{
							ans = z;
							valid = 1;
							break;
						}
						
					}
				}
				if(valid)
					break;
			}
			if(valid)
				break;
		}
		
		cout << ans << endl;
		

	}
}