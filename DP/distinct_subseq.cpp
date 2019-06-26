/*
	given two strings S and T
	find distinct subseq of S which is T.
	idea: if theres a match move both s and T or move only s
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int getDSS(string s1,string s2,int i,int j)
{
	// we found an occurence
	if(j == -1)
		return 1;
	// s fininished but no occurence
	if(i==-1)
		return 0;
	if(s1[i] != s2[j])
		return getDSS(s1,s2,i-1,j);

	// if matches then we have two choices
	return getDSS(s1,s2,i-1,j-1) + getDSS(s1,s2,i-1,j);
}

int getDSST(string s1,string s2)
{
	int n = s1.length();
	int m = s2.length();
	int dp[n+1][m+1];
	for(int i=0;i<=m;i++)
		dp[0][i] = 0;
	for(int i=0;i<=n;i++)
		dp[i][0] = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1] != s2[j-1])
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			}
		}
	}
	return dp[n][m];
}

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	int n1 = s1.length();
	int n2 = s2.length();
	int ans = getDSS(s1,s2,n1-1,n2-1);
	cout << ans << endl;
	ans = getDSST(s1,s2);
	cout << ans << endl;
}