#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[20][180][2];
vector<int> digit(ll n)
{
      vector<int> ret;
      while(n){
            ret.push_back(n%10);
            n=n/10;
      }
      return ret;
}
ll digitSum(vector<int> digit,int rem,int sum,int tight)
{
      if(rem == -1)
            return sum;
      if(dp[rem][sum][tight]!=-1)
            return dp[rem][sum][tight];
      ll ret = 0;
      int k = (tight==0)?9:digit[rem];
      for(int i=0;i<=k;i++)
      {
            tight = (digit[rem] == i)?1:0;
            ret += digitSum(digit,rem-1,sum+i,tight);
      }
      dp[rem][sum][tight] = ret;
      return ret;
}
int main()
{
      ll a,b;
      cin >> a >> b;
      memset(dp,-1,sizeof(dp));
      vector<int> d1 = digit(a-1);
      vector<int> d2 = digit(b);
      ll s1 = digitSum(d1,d1.size()-1,0,1);
      ll s2 = digitSum(d2,d2.size()-1,0,1);
      cout << s1 << " " << s2 << endl;
      cout << s2 - s1 << endl;
}
