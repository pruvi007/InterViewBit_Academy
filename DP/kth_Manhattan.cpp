#include<bits/stdc++.h>
using namespace std;

int main()
{
      int n,m;
      cin >> n >> m;
      int a[n][m];
      for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                  cin >> a[i][j];
      int k;
      cin >> k;
      int dp[k+1][n][m];
      int INF = INT_MIN;
      for(int d=0;d<=k;d++)
      {
            for(int i=0;i<n;i++)
            {
                  for(int j=0;j<m;j++)
                  {
                        if( d==0 )
                              dp[d][i][j] = a[i][j];
                        else
                        {
                              int cur = INF;
                              if( i>0 )
                                    cur = max( cur, dp[d-1][i-1][j] );
                              if( j>0 )
                                    cur = max( cur, dp[d-1][i][j-1] );
                              if( i<n-1 )
                                    cur = max( cur, dp[d-1][i+1][j] );
                              if( j<m-1 )
                                    cur = max( cur,dp[d-1][i][j+1] );
                              dp[d][i][j] = max( cur,dp[d-1][i][j] );
                        }
                  }
            }
      }

      for(int i=0;i<n;i++)
      {
            for(int j=0;j<m;j++)
                  a[i][j] = dp[k][i][j];
      }
      cout << endl;
      for(int i=0;i<n;i++)
      {
            for(int j=0;j<m;j++)
                  cout << a[i][j] << " ";
            cout << endl;
      }
}
