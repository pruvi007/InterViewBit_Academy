#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
      int n,k;
      cin >> n >> k;
      ll mod = 1e9+7;
      ll dp[n],a[n];
      for(int i=0;i<n;i++)
            cin >> a[i];
      if(n==1)
      {
            cout << 0 << endl;
      }
      else
      {
            dp[0] = 0;
            dp[1] = abs(a[1]-a[0]);
            for(int i=2;i<n;i++)
            {
                  dp[i] = mod;
                  for(int j=i-1;j>=i-k;j--)
                  {
                        if(j<0)
                              break;
                        dp[i] = min( dp[i],dp[j]+abs(a[i]-a[j]) );
                  }
            }
            cout << dp[n-1] << endl;
      }
}
