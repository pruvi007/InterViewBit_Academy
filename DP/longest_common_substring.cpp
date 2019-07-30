/*
	Find the longest common substring among the given strings
	idea is to use DP
	eg
	geeksforgeekquiz
	geekquiz
	(if same then +1 of previous indexes else 0)
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,p;
	cin >> s >> p;
	int n = s.length();
	int m = p.length();
	int dp[n+1][m+1];
	int ans = 0;
	int ind=-1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(s[i-1] == p[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
				ans = max(ans,dp[i][j]);
				ind = i-1;
			}
			else dp[i][j] = 0;
		}
	}
	string com = "";
	for(int i=ind;i>=0;i--)
	{
		if(s[i] == p[i])
			com += s[i];
	}
	reverse(com.begin(),com.end());
	cout << ans << endl;
	cout << com << endl;	
}
