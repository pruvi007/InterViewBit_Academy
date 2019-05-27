/*
       either move to (i+1,j) or (i,j+1) or (i+1, j+1). Please note that certain cells are forbidden and cannot be used.
*/

// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;

int a[1001][1001];
int flag[1001][1001];

ll c = 0;
int isSafe(int n,int m,int i,int j)
{
      if(i<n && i>=0 && j<m && j>=0 && a[i][j]==0)
            return 1;
      return 0;
}

void count_paths(int n,int m,int i,int j)
{
      if(i==n-1 && j==m-1)
      {
            c++;
            c %= mod;
            return ;
      }
      if(isSafe(n,m,i+1,j) && flag[i+1][j]==0)
      {
            flag[i+1][j] = 1;
            count_paths(n,m,i+1,j);
            flag[i+1][j] = 0;
      }
      if(isSafe(n,m,i,j+1) && flag[i][j+1]==0)
      {
            flag[i][j+1] = 1;
            count_paths(n,m,i,j+1);
            flag[i][j+1] = 0;
      }
      if(isSafe(n,m,i+1,j+1) && flag[i+1][j+1] == 0)
      {
            flag[i+1][j+1] = 1;
            count_paths(n,m,i+1,j+1);
            flag[i+1][j+1] = 0;
      }

}
int main()
{
      int t;
      cin>>t;
      while(t--)
      {
            int n,m,b;
            cin>>n>>m>>b;
            vector<pair<int,int> > fb;

            for(int i=0;i<n;i++)
            {
                  for(int j=0;j<m;j++)
                  {
                        a[i][j] = 0;
                        flag[i][j] = 0;
                  }
            }
            for(int i=0;i<b;i++)
            {
                  int x,y;
                  cin>>x>>y;
                  fb.push_back({x,y});
                  a[x][y] = 1;
            }
            c = 0;
            flag[0][0]=1;
            if(a[0][0])
                cout<<"0\n";
            else
            {
                count_paths(n,m,0,0);
                cout<<c<<endl;
            }

      }
}


// PS: it worked in one go... yo yo yoooooo backtracking is awesome...
