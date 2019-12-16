#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1e9 + 7;
ll dp[20][150][2];
vector<int> digit(ll n)
{
      vector<int> ret;
      while(n)
      {
            ret.push_back(n%10);
            n/=10;
      }
      reverse(ret.begin(),ret.end());
      return ret;
}

ll digitSum(vector<int> digit,ll k,int rem,ll curSum,int tight)
{
      if(rem==digit.size())
      {
            if(curSum%k==0)
                  return 1;
            return 0;
      }
      if(dp[rem][curSum][tight] != -1)
            return dp[rem][curSum][tight];
      int upper = (tight)?digit[rem]:9;
      ll ans = 0;
      for(int i=0;i<=upper;i++)
      {
            int curTight = (digit[rem]==i)?tight:0;
            ans += digitSum(digit,k,rem+1,curSum+i,curTight);
            ans %= mod;
      }
      dp[rem][curSum][tight] = ans;
      return ans;
}

int main()
{
      int a=1,b,k;
      cin >> b >> k;
      vector<int> d1,d2;
      d1 = digit(a-1);d2 = digit(b);

      memset(dp,-1,sizeof(dp));
      ll s1 = digitSum(d1,k,0,0,1);
      memset(dp,-1,sizeof(dp));
      ll s2 = digitSum(d2,k,0,0,1);
      cout << s2 - s1 << endl;
}
