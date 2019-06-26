/*
	Find the minimum time when all the fresh oranges become rotten
	idea: use multi source BFS from all the rotten oranges 
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
int board[1001][1001],v[1001][1001]={0},vis[1001][1001]={0};
int n,m;
bool isSafe(int i,int j)
{
	if(i<n && j<m && i>=0 && j>=0 && board[i][j]==1)
		return true;
	return false;
}
int main()
{
	cin >> n >> m;
	queue<pair<int,int> >  q;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> board[i][j];
			if(board[i][j]==2)
			{
				q.push({i,j});
				vis[i][j]=1;
			}
		}
	}

	// allowed movements (NSEW)
	int x[] = {-1,0,1,0};
	int y[] = {0,1,0,-1};
	int time = 0;
	while(!q.empty())
	{
		int n_size = q.size();
		int change = 0;
		for(int i=0;i<n_size;i++)
		{
			pair<int,int> p = q.front();
			q.pop();
			for(int j=0;j<4;j++)
			{
				int a = p.first + x[j];
				int b = p.second + y[j];
				if(isSafe(a,b) && vis[a][b]==0)
				{
					change = 1;
					board[a][b] = 2;
					q.push({a,b});
				}
			}
		}
		if(change==0)
			break;
		else 
			time++;
	}
	cout << endl;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(board[i][j]==1)
				flag=1;
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	if(flag)
		cout << "-1\n";
	else
		cout << time << endl;
}