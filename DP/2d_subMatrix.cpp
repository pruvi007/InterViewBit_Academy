#include<bits/stdc++.h>
using namespace std;

int subMatrix(vector< vector<int> > &v,int n,int m,int lim)
{
	int dp[n][m];
	for(int i=0;i<m;i++)
		dp[0][i]=v[0][i];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			dp[i][j]=dp[i-1][j]+v[i][j];
		}
	}

	int ans = INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int s=0;
			for(int k=0;k<m;k++)
			{
				if(i-1>=0)
					s+=dp[j][k]-dp[i-1][k];
				else
					s+=dp[j][k];

			}
			if(s>ans and s<=lim)
				ans=s;
		}
	}
	return ans;
}

int main(){
	int n,m,lim;
	cin >> n >> m >> lim;
	vector< vector<int> > a;
	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			temp.push_back(x);
		}
		a.push_back(temp);
	}
	int ans = subMatrix(a,n,m,lim);
	cout << ans << endl;
}