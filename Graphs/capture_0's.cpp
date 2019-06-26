/*
	Given a 2D board of o's and x's
	if any region of continuos o's is covered by x's in NSEW then that region can be captured.
	idea: only those o's will not be captured if any one of the o's of that region is on the boundary
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int n,m;
char board[1001][1001];
// movements allowed (NSEW)
int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};

bool isSafe(int i,int j)
{
	if(i<n && j<m && i>=0 && j>=0 && board[i][j]=='o')
		return true;
	return false;
}

void dfs(int i,int j)
{
	board[i][j] = 'z';
	for(int k=0;k<4;k++)
	{
		int a = i + x[k];
		int b = j + y[k];
		if(isSafe(a,b))
		{
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
			cin >> board[i][j];
	}

	// start marking the o's on the boundary that can't be captured (trigger DFS from those o's)
	// upper boundary
	for(int i=0;i<m;i++)
	{
		if(board[0][i] == 'o')
		{
			dfs(0,i);
		}
	}
	// right boundary
	for(int i=0;i<n;i++)
	{
		if(board[i][m-1] == 'o')
		{
			dfs(i,m-1);
		}
	}
	// lower boundary
	for(int i=0;i<m;i++)
	{
		if(board[n-1][i] == 'o')
		{
			dfs(n-1,i);
		}
	}
	// left boundary
	for(int i=0;i<n;i++)
	{
		if(board[i][0]=='o')
		{
			dfs(i,0);
		}
	}

	// now we have marked the regions which cant be captured 
	// so now move inside the board and mark all the zeros to be x then restore the non captured regions
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(board[i][j] == 'o')
				board[i][j]='x';
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(board[i][j] == 'z')
				board[i][j]='o';
		}
	}

	cout << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout << board[i][j] << " ";
		cout << endl;
	}



}