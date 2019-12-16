#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll INF = 1e6+1;
int main()
{
      int n,W;
      cin >> n >> W;
      vector< vector<ll> > a(n);
      for(int i=0;i<n;i++)
      {
            ll w,v;
            cin >> w >> v;
            a[i].push_back(w);
            a[i].push_back(v);
      }
      ll dp[W+1]={0};
      for(int i=0;i<n;i++)
      {
            for(int j=W;j>=a[i][0];j--)
            {
                  dp[j] = max( dp[j],a[i][1]+dp[j-a[i][0]] );
            }
      }
      cout << dp[W] << endl;
}
