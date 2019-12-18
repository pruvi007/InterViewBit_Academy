#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[1001][1001];
int burst(int a[],int l,int r,int n)
{
      if(dp[l][r]!=-1)
            return dp[l][r];
      int res = 0;
      for(int i=l+1;i<r;i++)
      {
            int cs = burst(a,l,i,n) + burst(a,i,r,n);
            if(l==0 and r==n)
                  cs+=a[i];
            else
                  cs+=a[l]*a[i]*a[r];
            if(cs>res)
                  res = cs;
      }
      dp[l][r] = res;
      return res;
}
int main()
{
      int n;
      cin >> n ;
      int a[n];
      memset(dp,-1,sizeof(dp));
      for(int i=0;i<n;i++)
            cin >> a[i];
      int dp[n+2];
      dp[0] = 1;dp[n+1] = 1;
      for(int i=1;i<=n;i++)
            dp[i] = a[i-1];
      int ans = burst(dp,0,n+1,n+1);
      cout << ans << endl;
}
