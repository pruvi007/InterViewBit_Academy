#include<bits/stdc++.h>
using namespace std;

int a[100][100];
int vis[100][100];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int sum = 0;

int isSafe(int n,int m,int i,int j)
{
	if(i<n && j<m && i>=0 && j>=0 && a[i][j]!=-1)
		return 1;
	return 0;

}

void paths1(int n,int m,int i,int j,int zeros,int hops)
{
	if(a[i][j] == 2)
	{
		sum += (hops==zeros+1?1:0);
		return ;

	}
	vis[i][j] = 0;
	for(int k=0;k<4;k++)
	{
		int x = i+dx[k];
		int y = j+dy[k];
		if(isSafe(n,m,x,y) && vis[x][y]==0)
		{
			paths1(n,m,x,y,zeros,hops+1);
		}
	}
	vis[i][j] = 1;
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
	paths1(n,m,sx,sy,zeros,0);

	cout<<sum<<endl;
}