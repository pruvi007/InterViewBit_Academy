
// nqueens problem
// print all solution of Nqueens for a given N

// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

char board[100][100];


int isSafe(int n,int row,int col)
{
	// check for left row if it contains a 'Q'
	for(int i=0;i<col;i++)
	{
		if(board[row][i]=='Q')
			return 0;
	}
	// check for upper left diagnol if contains a 'Q'
	int r = row,c = col;
	while(r>=0 && c>=0)
	{
		if(board[r][c]=='Q')
			return 0;
		r--;
		c--;
	}
	// check for lower left diagnol if it contains 'Q'
	r = row,c=col;
	while(row<n && c>=0)
	{
		if(board[r][c]=='Q')
			return 0;
		r++;
		c--;
	}

	return 1;

}

void N_Queens(int n,int col)
{
	if(col>=n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<board[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
		
	}

	
	for(int i=0;i<n;i++)
	{
		if(isSafe(n,i,col))
		{
			board[i][col] = 'Q';
		 	N_Queens(n,col+1);
			board[i][col] = '.';
		}
	}
	
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			board[i][j] = '.';
	}
	N_Queens(n,0);
}