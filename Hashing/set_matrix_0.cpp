// Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.  Do it in place.

// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

// idea is to mark the row and column if found 0 at i,j. Then make that row 0 then make column 0
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}
	int r[n]={0};
	int c[m]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==0)
			{
				a[i][0] = 0;
				r[i]=1;
				a[0][j] = 0;
				c[j]=1;

			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(a[i][0]==0)
		{
			if(r[i]==1)
			{
				for(int j=0;j<m;j++)
				{
					a[i][j]=0;
				}
			}
			
		}
	}

	for(int i=0;i<m;i++)
	{
		if(a[0][i]==0)
		{
			if(c[i]==1)
			{
				for(int j=0;j<n;j++)
				{
					a[j][i]=0;
				}
			}
			
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}