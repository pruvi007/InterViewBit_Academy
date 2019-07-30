/*
	Find minimum distance for a knight to reach to destination
	Idea: use BFS on the 8 safe cells and maintain level.
*/

#include<bits/stdc++.h>
using namespace std;
int board[1001][1001];
bool vis[1001][1001];
int n,m;

bool isSafe(int i,int j)
{
	if(i>=1 && i<=n && j>=1  && j<=m)
		return true;
	return false;
}
int knight(int sx,int sy,int dx,int dy)
{
	// 8 cells where a knight can jump
	int x[] = {-2, -1, 1, 2, -2, -1, 1, 2}; 
    int y[] = {-1, -2, -2, -1, 1, 2, 2, 1};

	queue<pair<int,pair<int,int> > > q;
	q.push({0,{sx,sy}});
	vis[sx][sy] = true;
	while(!q.empty())
	{
		pair<int,pair<int,int> > p = q.front();
		q.pop();

		int ai = p.second.first;
		int bi = p.second.second;
		// cout << ai << " " << bi << endl;
		if(ai == dx && bi == dy)
			return p.first;
		for(int j=0;j<8;j++)
		{
			int a = ai + x[j];
			int b = bi + y[j];
			// cout << a << " " << b << endl;
			if(isSafe(a,b) && vis[a][b]==false)
			{
				q.push({p.first+1,{a,b}});
				vis[a][b] = true;
			}
		}
		
	}
	return -1;
}
int main()
{
	
	cin >> n >> m;
	int sx,sy,dx,dy;
	cin >> sx >> sy >> dx >> dy;
	
	memset(board,0,sizeof(board));
	memset(vis,false,sizeof(vis));
	int ans = knight(sx,sy,dx,dy);
	cout << ans << endl;
}