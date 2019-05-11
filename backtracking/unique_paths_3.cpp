#include<bits/stdc++.h>
using namespace std;

int a[100][100];
int vis[100][100];

int isSafe(int n,int m,int i,int j)
{
	if(i<n && j<m && i>=0 && j>=0 && a[i][j]!=-1)
		return 1;
	return 0;

}
int paths1(int n,int m,int i,int j,int zeros,int hops)
{
	if(a[i][j] == 2)
	{
		return hops==zeros+1?1:0;

	}
	static int sum = 0;
	if(isSafe(n,m,i,j+1) && vis[i][j+1]==0)
	{
		vis[i][j+1] = 1;
		sum += paths1(n,m,i,j+1,zeros,hops+1);
		vis[i][j+1] = 0; 
	}
	else if(isSafe(n,m,i,j-1) && vis[i][j-1]==0)
	{
		vis[i][j-1] = 1;
		sum += paths1(n,m,i,j-1,zeros,hops+1);
		vis[i][j-1] = 0; 
	}
	else if(isSafe(n,m,i+1,j) && vis[i+1][j]==0)
	{
		vis[i+1][j] = 1;
		sum += paths1(n,m,i+1,j,zeros,hops+1);
		vis[i+1][j] = 0; 
	}
	else if(isSafe(n,m,i-1,j) && vis[i-1][j]==0)
	{
		vis[i-1][j] = 1;
		sum += paths1(n,m,i-1,j,zeros,hops+1);
		vis[i-1][j] = 0; 
	}
	return sum;
}
int paths2(int n,int m,int i,int j,int zeros,int hops)
{
	if(a[i][j] == 2)
	{
		return hops==zeros+1?1:0;

	}
	static int sum = 0;
	if(isSafe(n,m,i,j-1) && vis[i][j-1]==0)
	{
		vis[i][j-1] = 1;
		sum += paths1(n,m,i,j-1,zeros,hops+1);
		vis[i][j-1] = 0; 
	}
	// return sum;
}
int paths3(int n,int m,int i,int j,int zeros,int hops)
{
	if(a[i][j] == 2)
	{
		return hops==zeros+1?1:0;

	}
	static int sum = 0;
	if(isSafe(n,m,i+1,j) && vis[i+1][j]==0)
	{
		vis[i+1][j] = 1;
		sum += paths1(n,m,i+1,j,zeros,hops+1);
		vis[i+1][j] = 0; 
	}
	// return sum;
}
int paths4(int n,int m,int i,int j,int zeros,int hops)
{
	if(a[i][j] == 2)
	{
		return hops==zeros+1?1:0;

	}
	static int sum = 0;
	if(isSafe(n,m,i-1,j) && vis[i-1][j]==0)
	{
		vis[i-1][j] = 1;
		sum += paths1(n,m,i-1,j,zeros,hops+1);
		vis[i-1][j] = 0; 
	}
	// return sum;
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	int zeros = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j] == 0)
				zeros++;
		}
	}
	int sx=-1,sy=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j] == 1)
			{
				sx = i;
				sy = j;
				break;
			}
		}
		if(sx!=-1 && sy!=-1)
			break;
	}

	vis[n][m] = {0};
	int d1 = paths1(n,m,sx,sy+1,zeros,0);

	vis[n][m] = {0};
	int d2 = paths2(n,m,sx,sy,zeros,0);

	vis[n][m] = {0};
	int d3 = paths3(n,m,sx,sy,zeros,0);

	vis[n][m] = {0};
	int d4 = paths4(n,m,sx,sy,zeros,0);

	cout<<d1<<endl;
}