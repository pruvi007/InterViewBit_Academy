/*
	Given A regex tell whether it will match the given string or not
	?->will match any 1 char
	*-> will match any continuos seq of chars including empty
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;


bool wildCard(string s,string r)
{
	int n = s.length();
	int m = r.length();
	
// 	empty pattern will match only to empty string
	if(m==0)
	    return n==0;
	
	    
	bool dp[n+1][m+1];
	memset(dp,false,sizeof(dp));

	dp[0][0] = true;
	// empty string can only be matched with *
	for(int i=1;i<=m;i++)
	{
		// will be 1 till we can see a '*'
		if(r[i-1]=='*')
			dp[0][i] = dp[0][i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(r[j-1] == '*')
			{
				// either eat the char or leave the char(empty match)
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			}
			// if actual match or a ? eat it up and move
			else if(r[j-1] == s[i-1] || r[j-1]=='?')
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
				dp[i][j] = false;
		}
	}
	return dp[n][m];

}

int main()
{
	string s;
	string r;
	getline(cin,s);
	getline(cin,r);
	int n1 = s.length();
	int n2 = r.length();

	int ans = wildCard(s,r);
	cout << ans << endl;
}