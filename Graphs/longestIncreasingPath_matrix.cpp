#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN = 1e4;
int a[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool safe(int i,int j)
{
      return i>=0 and i<n and j>=0 and j<m;
}
int M = 0;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void findPaths( int i,int j,int count)
{
      if( !safe(i,j) )
            return ;

      vis[i][j] = true;
      for(int z=0;z<4;z++)
      {
            int ni = i+dx[z];
            int nj = j+dy[z];
            if( vis[ni][nj]==false and safe(ni,nj) )
            {
                  if( a[ni][nj] > a[i][j] )
                  {
                        M = max(M,count+1);
                        findPaths( ni,nj,count+1);
                  }
            }
      }
      vis[i][j] = false;
}
int main()
{
      cin >> n >> m ;

      for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                  cin >> a[i][j] ;
      int dp[n][m] ;
      memset( vis,false,sizeof(vis) );
      for(int i=0;i<n;i++)
      {
            for(int j=0;j<m;j++)
            {

                  M = 1;
                  findPaths( i,j,1);
                  dp[i][j] = M;
            }
      }
      cout << endl;
      M = 0;
      for(int i=0;i<n;i++)
      {
            for(int j=0;j<m;j++)
            {
                  cout << dp[i][j] << " ";
                  M = max(M,dp[i][j]);
            }

            cout << endl;
      }
      cout << M << endl;

}
