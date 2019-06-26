/*
	Gievn a string of integers find ways to decode into alphabets
	idea: to consider single and valid pairs.
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n = s.length();
	int dp[n+1];
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2;i<=n;i++)
	{
		dp[i] = 0;
		if(s[i-1]>'0')
			dp[i] = dp[i-1];
		if(s[i-2]=='1' || s[i-2]=='2' && s[i-1]<'7')
		{
			dp[i] += dp[i-2];
		}
	}
	cout << dp[n] << endl;
}
