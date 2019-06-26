/*
	Find the nearest 1 from every cell
	idea: use multi source BFS (push all sources at once inside the queue)
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
	queue<pair<int,pair<int,int> > > q;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> board[i][j];
			if(board[i][j]==1)
			{
				q.push({0,{i,j}});
				vis[i][j]=1;
			}
		}
	}

	int x[] = {-1,0,1,0};
	int y[] = {0,1,0,-1};


	while(!q.empty())
	{
		int n_size = q.size();
		for(int i=0;i<n_size;i++)
		{
			pair<int,pair<int,int> > p = q.front();
			q.pop();
			int xc = p.second.first;
			int yc = p.second.second;
			if(v[xc][yc]==0)
			{
				v[xc][yc] = p.first;
			}
			for(int j=0;j<4;j++)
			{
				int a = p.second.first + x[j];
				int b = p.second.second + y[j];
				if(isSafe(a,b) && vis[a][b]==0)
				{
					vis[a][b]=1;
					q.push({p.first+1,{a,b}});
				}
			}
		}
	}
	cout << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout << v[i][j]<<" ";
		cout << endl;
	}

}



// IB solution submitted
/*
bool isSafe(vector<vector<int> > &board,int i,int j)
{
    int n = board.size();
    int m = board[0].size();
	if(i<n && j<m && i>=0 && j>=0 && board[i][j]==0)
		return true;
	return false;
}

vector<vector<int> > Solution::solve(vector<vector<int> > &board) {
    
            
    int n = board.size();
    int m = board[0].size();
    int vis[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            vis[i][j] = 0;
            
    vector<vector<int> > v;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<m;j++)
            temp.push_back(0);
        v.push_back(temp);
    }
        
            
    queue<pair<int,pair<int,int> > > q;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(board[i][j]==1)
			{
			    v[i][j]=0;
				q.push({0,{i,j}});
				vis[i][j]=1;
			}
		}
	}

	int x[] = {-1,0,1,0};
	int y[] = {0,1,0,-1};


	while(!q.empty())
	{
		int n_size = q.size();
		for(int i=0;i<n_size;i++)
		{
			pair<int,pair<int,int> > p = q.front();
			q.pop();
			int xc = p.second.first;
			int yc = p.second.second;
			if(v[xc][yc]==0)
			{
				v[xc][yc] = p.first;
			}
			for(int j=0;j<4;j++)
			{
				int a = p.second.first + x[j];
				int b = p.second.second + y[j];
				if(isSafe(board,a,b) && vis[a][b]==0)
				{
					vis[a][b]=1;
					q.push({p.first+1,{a,b}});
				}
			}
		}
	}
	return v;
}
*/