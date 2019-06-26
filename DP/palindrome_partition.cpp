/*
	Find min cuts such that each portion is a palindrome

*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

// pal array will tell whether from (i,j) is a palindrome or not
int pal[1001][1001];

int main()
{
	string s;
	cin >> s;
	int n = s.length();

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			pal[i][j] = 0;
	}

	// the pal array is very important to get the palindrome info in O(1) time
	// all 1 length char are pals
	for(int i=0;i<=n;i++)
		pal[i][i] = 1;
	// check from length =2
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			// ending index
			int j = i+l-1;
			if(l==2)
			{
				// for length 2 just check the two chars
				pal[i][j] = (s[i]==s[j]);
			}
			else
			{
				// else if a match is found then check for the rest.
				pal[i][j] = (s[i]==s[j]) && pal[i+1][j-1];
			}
		}
	}
	
	int dp[n];
	// return 0 if from(i,j) is a palindrome
	for(int i=0;i<n;i++)
	{
		// this part checks the previous part
		if(pal[0][i]==1)
			dp[i]=0;
		else
		{
			// this part checks the ahead part
			dp[i] = INT_MAX;
			for(int j=0;j<i;j++)
			{
				if(pal[j+1][i] == true)
					dp[i] = min(dp[i],1+dp[j]);
			}
		}
	}




	int ans = dp[n-1];
	cout << ans << endl;
}