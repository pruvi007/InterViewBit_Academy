#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int mod = 1e9+7;
int dp[100001][101];
int candies( int a[],int n,int k,int level/*,vector<int> temp*/)
{

      if(k>=0 and dp[k][level]!=-1)
            return dp[k][level];

      if(level==n)
      {
            if(k==0)
            {
                  // for(int i=0;i<temp.size();i++)
                  //       cout << temp[i] << " ";
                  // cout << endl;
                  return 1;
            }

            return 0;
      }


      int ans = 0;
      for(int i=0;i<=a[level];i++)
      {
            /*vector<int> t;
            t = temp;
            t.push_back(i);*/
            if(k-i < 0)
                  break;
            ans += candies( a,n,k-i,level+1/*,t */);
            ans %= mod;
      }
      dp[k][level] = ans;
      return ans;
}
int main()
{
      int n,k;
      cin >> n >> k;
      int a[n];
      memset(dp,-1,sizeof(dp));
      for(int i=0;i<n;i++)
            cin >> a[i];
      vector<int> temp;
      int ans = candies( a,n,k,0/*,temp*/ );
      cout << ans << endl;
}
