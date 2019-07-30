/*
	Find the shortest path in a maze where a ball is travelling.
	Ball stops and changes direction iff it hits a boundary or a wall.
	Idea: use dfs and find and a distance matrix to update distances.
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
int dis[1001][1001];
int maze[1001][1001];
int n,m;
int xs[] = {-1,1,0,0};
int ys[] = {0,0,1,-1};

void dfs(int i,int j)
{
	for(int k=0;k<4;k++)
	{
		// start with one of the directions
		int a = i + xs[k];
		int b = j + ys[k];
		int count = 0;

		// keep moving in that direction like a ball untill you hit a wall or a boundary
		while(a>=0 && b>=0 && a<n && b<m && maze[a][b]==0)
		{
			count++;
			a += xs[k];
			b += ys[k];
		}
		// now we have reached at the co-ordinates of a wall or outside maze
		// now check the last good position's distacne from start
		a = a - xs[k];
		b = b - ys[k];

		if( dis[a][b] > dis[i][j]+count )
		{
			dis[a][b] = dis[i][j]+count;
			// start dfs from that last good position
			dfs(a,b);
		}
	}
}	
int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin >> maze[i][j];
	}
	int sx,sy;
	cin >> sx >> sy;
	int dx,dy;
	cin >> dx >> dy;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
			dis[i][j] = INT_MAX;
	}
	dis[sx][sy] = 0;
	dfs(sx,sy);
	// for(int i=0;i<n;	i++)
	// {
	// 	for(int j=0;j<m;j++)
	// 	{
	// 		if(dis[i][j]==INT_MAX)
	// 			cout << -1 << " ";
	// 		else cout << dis[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	if(dis[dx][dy] == INT_MAX)
		cout << -1 << endl;
	else cout << dis[dx][dy] << endl;

}