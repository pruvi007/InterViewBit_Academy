#include<bits/stdc++.h>
using namespace std;
#define ll              long long int
#define fill(a,b)       memset(a,b,sizeof(a))
const int N = (int) 1e4 + 5;
int n;
int dp[1001][1001];
int parent(int par[],int x)
{
      while(x!=par[x])
            x = par[x];
      return x;
}
bool find(int par[],int x,int y)
{
      return parent(par,x) == parent(par,y);
}


int doUnion(int par[],int size[],int x,int y)
{
      if( find(par,x,y) )
            return -1;
      int p1,p2,s1,s2;
      p1 = par[x];p2 = par[y];
      s1 = size[p1];s2 = size[p2];
      if(s1 > s2)
      {
            par[p2] = p1;
            size[p1] += s2;
      }
      else
      {
            par[p1] = p2;
            size[p2] += s1;
      }
      return 1;
}


int solve(vector<int> size_count,vector<int> cost,int pos,int rem)
{
      if( dp[pos][rem]!=-1)
            return dp[pos][rem];
      if(rem<=0)
            return 0;
      if(pos>=cost.size())
            return 5e8;

      int ans = 5e8;
      int a = solve( size_count,cost,pos+1,rem );
      int b = cost[pos] + solve( size_count,cost,pos+1,rem-size_count[pos] );
      ans = min( ans,min(a,b) );
      dp[pos][rem] = ans;
      return ans;
}
int main()
{
      int m,k;
      cin >> n >> m >> k;
      fill(dp,-1);
      // init dsu
      int par[n+1],size[n+1];
      for(int i=1;i<=n;i++)
      {
            par[i] = i;
            size[i] = 1;
      }
      for(int i=0;i<m;i++)
      {
            int x,y;
            cin >> x >> y;
            int u = doUnion(par,size,x,y);
      }
      set<int> s;
      int M[n+1];
      memset(M,999999,sizeof(M));
      for(int i=1;i<=n;i++)
      {
            s.insert(par[i]);
            M[par[i]] = min(M[par[i]],i);
      }

      vector<int> size_count,cost;
      for(auto it:s)
      {
            // cout << it << " ";
            size_count.push_back(size[it]);
            cost.push_back(M[it]);
      }
      // for(int i=0;i<cost.size();i++)
      //       cout << size_count[i] << " " << cost[i] << endl;
      int ans = solve(size_count,cost,0,k);
      cout << ans << endl;

}
