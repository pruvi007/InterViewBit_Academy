#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[3002][3002];
ll game(ll a[],int n,int l,int r)
{
      if(dp[l][r]!=-1)
            return dp[l][r];

      if( l==r )
            return a[l];

      ll x = a[l] - game(a,n,l+1,r);
      ll y = a[r] - game(a,n,l,r-1);
      dp[l][r] = max(x,y);
      return dp[l][r];
}
int main()
{
      // taro tries to maximizes X-Y -> means Taro wants to earn max Possible points
      // Jiro tries to minimize X-Y -> means Jiro wants to earn max Possible points
      // hence, in each their turns they will try to get the best Possible ans.
      int n;
      cin >> n ;
      ll a[n];
      memset( dp,-1,sizeof(dp) );
      ll total = 0;
      for(int i=0;i<n;i++)
      {
            cin >> a[i];
            total += a[i];
      }

      ll ans = game( a,n,0,n-1 );
      cout << ans << endl;
}
