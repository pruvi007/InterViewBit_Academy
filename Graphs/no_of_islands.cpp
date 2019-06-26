/*
	Find the total islands present inside a matrix
	idea: total no of dfs calls will be the total islands
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
int n,m;
int board[100][100];
// movement on board
int x[] = {-1,-1,-1,0,0,1,1,1};
int y[] = {-1,0,1,-1,1,-1,0,1};

bool isSafe(int i,int j)
{
	if(i<n && j<m && i>=0 && j>=0 && board[i][j]==1)
		return true;
	return false;
}

void dfs(int i,int j)
{
	board[i][j] = 0;
	for(int k=0;k<8;k++)
	{
		int a = i+x[k];
		int b = j+y[k];
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

	int islands = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(board[i][j] == 1)
			{
				cout << i << " " << j << endl;
				dfs(i,j);
				islands++;
			}
		}
	}


	cout << islands << endl;
}