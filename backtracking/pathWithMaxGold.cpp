int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool safe(int x,int y,vector<vector<int>>&grid){
    int n,m;
    n = grid.size();
    m = grid[0].size();
    return x>=0 and x<n and y>=0 and y<m and grid[x][y];
}
int M;
void dfs(int si,int sj,vector<vector<int>> &grid,set<pair<int,int>>&s,int val)
{
    // mark this visited and explore all paths
    s.insert({si,sj});
    M = max(M,val);
    for(int i=0;i<4;i++)
    {
        int nx = si+dx[i];
        int ny = sj+dy[i];
        if( safe(nx,ny,grid) and s.find({nx,ny})==s.end() )
        {
            dfs(nx,ny,grid,s,val+grid[nx][ny]);
        }
    }
    // backtrack to explore any other set of paths
    s.erase({si,sj});
    
}

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n,m;
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        set<pair<int,int> > s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    
                    M = 0;
                    dfs(i,j,grid,s,grid[i][j]);
                    ans = max(ans,M);
                }
                
            }
        }
        return ans;
        
    }
};