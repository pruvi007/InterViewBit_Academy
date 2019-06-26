/*
	Perform matrix chain multiplication such that the number of operations are minimized
	idea: for every i go from 0 to j and find for every partition

*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int matrix(vector<pair<int,int> > &v,int i,int j)
{
	if(i==j)
		return 0;
	int cMin = INT_MAX;
	int c;
	for(int k=i;k<j;k++)
	{
		c = matrix(v,i,k) + matrix(v,k+1,j) + (v[i].first*v[k].second*v[j].second);
		if(c < cMin)
			cMin = c;
	}
	return cMin;
}

int matrix_T(vector<int> &v)
{
	int n = v.size();
	int dp[n][n];
	for(int i=1;i<n;i++)
		dp[i][i]=0;
	for(int l=2;l<n;l++)
	{
		for(int i=1;i<n-l+1;i++)
		{
			int j = i+l-1;
			dp[i][j]=INT_MAX;
			for(int k=i;k<j;k++)
			{
				int c = dp[i][k] + dp[k+1][j] + (v[i-1]*v[k]*v[j]);
				if(c<dp[i][j])
					dp[i][j] = c;
			}

		}
	}
	return dp[1][n-1];
}
int main()
{
	int n;
	cin >> n;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	vector<pair<int,int> > v;
	for(int i=1;i<n;i++)
	{
		int l = a[i-1];
		int r = a[i];
		v.push_back({l,r});
	}
	int ans = matrix(v,0,v.size()-1);
	cout << ans << endl;
	ans = matrix_T(a);
	cout << ans << endl;
}