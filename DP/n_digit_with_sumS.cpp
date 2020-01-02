#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[101][920][2];
int mod = 1e9+7;
int solve(vector<int> digit,int S,int rem,int sum,int tight)
{
      if( dp[rem][sum][tight]!=-1 )
            return dp[rem][sum][tight]%mod;
      if( rem==digit.size() )
      {
            if( sum==S )
                  return 1;
            return 0;
      }
      int upper = tight?digit[rem]:9;
      int ans = 0;
      for(int i=0;i<=upper;i++)
      {
            if(sum+i > S)
                  continue;
            int newTight = (digit[rem]==i)?tight:0;
            ans = ( ans + solve( digit,S,rem+1,sum+i,newTight ) )%mod;
            ans %= mod;

      }
      dp[rem][sum][tight] = ans%mod;
      return ans%mod;
}
int lookup[101][901];
int sum( int rem,int S )
{
      if( lookup[rem][S] != -1)
            return lookup[rem][S];
      if( rem==0 )
            return S == 0;
      int ans = 0;
      for(int i=0;i<=9;i++)
      {
            if( S-i >= 0 )
            {
                  ans += sum( rem-1,S-i );
                  ans %= mod;
            }

      }
      lookup[rem][S] = ans%mod;
      return ans%mod;
}
int main()
{
      int n,s;
      cin >> n >> s;
      // vector<int> d1,d2;
      // for(int i=0;i<n-1;i++)
      //       d1.push_back(9);
      //
      // for(int i=0;i<n;i++)
      //       d2.push_back(9);
      // memset(dp,-1,sizeof(dp));
      // int s1 = solve( d1,s,0,0,1 );
      // memset(dp,-1,sizeof(dp));
      // int s2 = solve( d2,s,0,0,1 );
      // if( s1<0 ) s1+=mod;
      // if( s2<0 ) s2+=mod;
      // cout << s1 << " " << s2 << endl;
      // cout << s2-s1 << endl;
      int ans = 0;
      for(int i=1;i<=9;i++)
      {
            memset( lookup,-1,sizeof(lookup) );
            if( s-i>=0 )
                  ans += sum( n-1,s-i );
            ans %= mod;
      }

      cout << ans%mod << endl;

}
