/*
	Find the LONGEST COMMON SUBSEQ
	both methods: Memoize + Tabularize
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> m;
int lcs(string s1,string s2,int i,int j)
{
	if(i>=s1.length() || j>=s2.length())
		return 0;
	if(m.find({i,j}) != m.end())
		return m[{i,j}];
	else if(s1[i]==s2[j])
	{
		m[{i,j}] = 1 + lcs(s1,s2,i+1,j+1);
		return m[{i,j}];
	}
	else
	{
		m[{i,j}] = max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
		return m[{i,j}];
	}
}

string sl = "";
int lcsT(string s1,string s2)
{
	int n = s1.length();
	int m = s2.length();
	int dp[n+1][m+1];
	for(int i=0;i<=m;i++)
		dp[0][i]=0;
	for(int j=0;j<=n;j++)
		dp[j][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{	
			if(s1[i] == s2[j])
			{
				dp[i+1][j+1] = 1 + dp[i][j];
			}
			else
			{
				dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
			}
		}
	}
	

	stack<char> stk;
	int l=n,r=m;
	while(1)
	{
		if(dp[l][r] == 0)
			break;
		if(s1[l-1] == s2[r-1])
		{
			stk.push(s1[l-1]);
			l--;
			r--;
		}
		else if(s1[l-1]!=s2[r-1])
		{
			int a = dp[l-1][r];
			int b = dp[l][r-1];
			if(a > b)
				l--;
			else r--;
		}
	}

	while(!stk.empty())
	{
		sl += stk.top();
		stk.pop();
	}
	return dp[n][m];


}
int main()
{
	string s1,s2;
	cin >> s1;
	cin >> s2;
	int n1 = s1.length();
	int n2 = s2.length();
	int ans = lcs(s1,s2,0,0);
	cout << ans << endl;
	ans = lcsT(s1,s2);
	cout << ans << endl;
	cout << sl << endl;
}