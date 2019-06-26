/*
	Given two strings you need to convert string1 to string2 in min operations 
	op = {insert,delete,replace}
	idea: do all three at a given index and find the min
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int ED[1001][1001]={NULL};
int edit_distance(string s1,string s2,int i,int j)
{
	// 0 ops reqd to convert empty to empty
	if(i<0 && j<0)
		return 0;
	// if s1 is finished then j+1 inserts
	if(i<0 && j>=0)
		return j+1;
	// if s2 is finished then i+1 deletes
	if(i>=0 && j<0)
		return i+1;

	if(s1[i] == s2[j])
	{
		return edit_distance(s1,s2,i-1,j-1);
	}
	int del,rep,ins;
	
	del = edit_distance(s1,s2,i-1,j);
	rep = edit_distance(s1,s2,i-1,j-1);
	ins = edit_distance(s1,s2,i,j-1);

	return 1 + min(min(del,rep),ins);
	
	
}

int editT(string s1,string s2)
{
	int n = s1.length();
	int m = s2.length();
	int dp[n+1][m+1];
	for(int i=0;i<=m;i++)
		dp[0][i] = i;
	for(int j=0;j<=n;j++)
		dp[j][0] = j;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
			{
				int del = dp[i-1][j];
				int ins = dp[i][j-1];
				int rep = dp[i-1][j-1];
				dp[i][j] = 1 + min(min(del,ins),rep);

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
	// cout << n1 << " " << n2 << endl;
	int ans = edit_distance(s1,s2,n1-1,n2-1);
	cout << ans << endl;
	ans = editT(s1,s2);
	cout << ans << endl;

}