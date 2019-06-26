/*
	given a string find whether it can be segmented into given list of words
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

map<string,int> word;
int isPresent(string s)
{
	// cout << s << endl;
	if(word.find(s)!=word.end())
	    return 1;
	return 0;
}
map<pair<int,int>,bool> m;
bool word_break(vector<string> &v, string s)
{
	int n = s.length();
	if(n==0)
		return true;
	for(int i=1;i<=n;i++)
	{
		if(m.find({i,n-i})!=m.end())
		{
			if(isPresent(s.substr(0,i)) && m[{i,n-i}])
				return true;
		}
		else
		{
			m[{i,n-i}] = word_break(v,s.substr(i,n-i));
			if(isPresent(s.substr(0,i)) && m[{i,n-i}])
				return true;

		}
		
	}
	return false;
}

bool word_breakT(string s)
{
	int n = s.length();
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));

	for(int l=1;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j = i+l-1;
			if( isPresent(s.substr(i,j+1)) )
				dp[i][j]=1;
			else
			{
				for(int k=i+1;k<=j;k++)
				{
					if(dp[i][k-1]!=0 && dp[k][j]!=0)
					{
						dp[i][j]=1;
						break;
					}
				}
			}
		}
	}
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
		
	return dp[0][n-1];
}

bool word_break_2(string s)
{
	int n = s.length();
	int dp[n];
	dp[0] = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(dp[j]==1 && isPresent(s.substr(j,i)))
			{
				dp[i]=1;
				break;
			}
		}
	}
	return dp[n-1];
}

int main()
{
	string s;
	cin >> s;
	// cout << s.substr(0,4);
	int n = s.length();
	int m;
	cin >> m;
	vector<string> v;
	for(int i=0;i<m;i++)
	{
		string x;
		cin >> x;
		v.push_back(x);
		word[x] = 1;
	}

	int ans = word_break_2(s);
	cout << ans << endl;

}