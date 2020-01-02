#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 100001, size = 500;
int n;
ll a[MAXN],dp[size][size],pre[MAXN];

ll answer(int l,int r)
{
      if(l>r)
            return INT_MAX;
      return pre[r]-pre[l-1];
}
ll slime(int l,int r)
{
      if( dp[l][r]!=-1 )
            return dp[l][r];

      if( l==r )
            return 0;
      if(l+1==r)
            return a[r]+a[l];
      ll ans = INT_MAX;
      for(int i=l;i<=r;i++)
      {
            ll local = slime( l,i ) + slime( i+1,r ) + answer( l,r );
            ans = min(local,ans);
      }
      dp[l][r] = ans;
      return ans;
}
int main(){
      memset(dp,-1,sizeof(dp));
      cin >> n;
      for(int i=0;i<n;i++)
      {
            cin >> a[i];
            if(i==0)
                  pre[i] = a[i];
            else
                  pre[i] = pre[i-1]+a[i];
      }
      ll ans  = slime(0,n-1);
      cout << ans << endl;



}
