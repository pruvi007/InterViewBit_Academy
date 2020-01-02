#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4+1;
int dp[MAXN][100][2];
int mod = 1e9+7;
int solve( string k,int d,int rem,int sum,int tight ){
      if( rem == k.length() )
            return sum%d==0;
      if( dp[rem][sum][tight]!=-1 )
            return dp[rem][sum][tight];

      int upper = tight?(k[rem]-'0'):9;
      int ans = 0;
      for(int i=0;i<=upper;i++)
      {
            int newTight = (k[rem]-'0')==i ? tight:0;
            ans = (ans + solve(k,d,rem+1,(sum+i)%d,newTight) )%mod;
      }
      dp[rem][sum][tight] = ans%mod;
      return ans%mod;
}
int main(){
      string k;
      int d;
      cin >> k;
      cin >> d;
      memset( dp,-1,sizeof(dp) );
      int ans = solve( k,d,0,0,1 );
      cout << (ans-1)%mod << endl;
}
