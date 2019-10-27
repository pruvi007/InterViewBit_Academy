#include<bits/stdc++.h>
using namespace std;

int dp1[1001][1001],dp2[1001][1001];
string lps(string a,int flag)
{
	string A = a;
	int l = a.length();
	reverse(a.begin(),a.end());

	for(int i=0;i<=l;i++)
		dp[0][i] = 0;
	for(int i=0;i<=l;i++)
		dp[i][0] = 0;
	for(int i=1;i<=l;i++)
	{
		for(int j=1;j<=l;j++)
		{
			if( A[i-1] == a[j-1] )
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	for(int i=0;i<=l;i++)
	{
		for(int j=0;j<=l;j++)
		{
			if( flag==1 )
			{
				
			}
		}
		
	}
	return dp[l][l];

}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string a,b;
		cin >> a >> b;
		int l1 = a.length(),l2 = b.length();
		
		int lpsA = lps(a);
		int lpsB = lps(b);
	}
}