// the knight's tour problem - visit all the squares of the chess . Visit one square only once.

#include<bits/stdc++.h>
using namespace std;
int board[100][100];

int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 }; 
int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 }; 

int isSafe(int n,int r,int c)
{

	if(r<n && c<n && r>=0 && c>=0 && board[r][c]==0)
		return 1;
	return 0;
}
void Knight_Tour(int n,int r,int c,int moves)
{
	if(moves>=n*n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<board[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
		
		return ;
	}
	
	for(int i=0;i<8;i++)
	{
		int next_i = r + xMove[i];
		int next_j = c + yMove[i];

		if(isSafe(n,next_i,next_j))
		{
			board[next_i][next_j] = moves;
			Knight_Tour(n,next_i,next_j,moves+1);
			board[next_i][next_j] = 0;
		}
	}
	return ;

}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			board[i][j] = 0;
			// cout<<board[i][j];
		}
		// cout<<endl;
	}
	// starting pos of knight;
	int i,j;
	cin>>i>>j;
	board[i][j] = 1;
	Knight_Tour(n,i,j,1);
}