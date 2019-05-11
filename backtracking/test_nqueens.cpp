#include<bits/stdc++.h>
using namespace std;


vector<vector<string> > v;
vector<string> board;

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
	r = row;c=col;
	while(row<n && c>=0)
	{
		if(board[r][c]=='Q')
			return 0;
		r++;
		c--;
	}

	return 1;

}
void nqueens(int n,int col)
{
    if(col>=n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<board[i]<<endl;
        }
        // v.push_back(board);
       
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(n,i,col))
        {
            board[i][col] = 'Q';
            nqueens(n,col+1);
            board[i][col] = '.';
        }
    }
}

int main()
{
    // v.clear();
    // board.clear();
    int A;
    cin>>A;


    if(A==1)
    {
        string temp="Q";
        board.push_back(temp);
        // v.push_back(board);

        // for(int i=0;i<v.size();i++)
        // {
        //     for(int j=0;j<v[i].size();j++)
        //         cout<<v[i][j]<<endl;
        // }
        
    }
    string temp="";
    for(int i=0;i<A;i++)
        temp+='.';
        
    for(int i=0;i<A;i++)
    {
        board.push_back(temp);
        cout<<board[i]<<endl;
    }
    
    nqueens(A,0);
    // for(int i=0;i<v.size();i++)
    // {
    //     for(int j=0;j<v[i].size();j++)
    //         cout<<v[i][j]<<endl;
    // }
    
}
