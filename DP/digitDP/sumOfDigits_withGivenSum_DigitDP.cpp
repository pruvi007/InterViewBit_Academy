#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[20][140][2];
vector<int> digit(ll n)
{
      vector<int> ret;
      while(n>0){
            ret.push_back(n%10);
            n/=10;
      }

      reverse(ret.begin(),ret.end());
      // for(int i=0;i<ret.size();i++)
      //       cout << ret[i] ;
      // cout << endl;
      return ret;
}
int sum(ll n)
{
      int s = 0;
      while(n)
      {
            s+=n%10;
            n/=10;
      }
      return s;
}
ll digitSum(vector<int> digit,int rem,int tight,ll curSum,ll sum)
{
      if(rem==digit.size())
      {
            if(curSum==sum)
                  return 1;
            return 0;
      }

      if(dp[rem][curSum][tight]!=-1)
            return dp[rem][curSum][tight];

      int k = (tight)?digit[rem]:9;
      ll ans = 0;
      for(int i=0;i<=k;i++)
      {
            if(curSum+i > sum)
                  continue;
            int curTight = (digit[rem]==i)?tight:0;
            ans += digitSum(digit,rem+1,curTight,curSum+i,sum);
      }
      dp[rem][curSum][tight] = ans;
      return ans;
}

ll smallest(ll low,ll high,ll s,ll L,ll R)
{
      vector<int> ans;
      ll small = 0;
      for(int i=low;i<=high;i++)
      {
            vector<int> num(i);
            int cur = s-1;
            for(int j=i-1;j>=0;j--)
            {
                  if(cur>9)
                        num[j]=9;
                  else
                        num[j]=cur;
                  cur-=num[j];
                  if(s==0)
                        break;
            }
            num[0] += 1;
            cur = 0;
            ll tNum = 0;
            for(int j=0;j<i;j++)
            {
                  cout << num[j];
                  cur+=num[j];
                  tNum = tNum*10 + num[j];
            }
            cout << endl;
            if(cur == s and tNum>=L and tNum<=R)
            {
                  ans = num;
                  break;
            }
      }
      for(int i=0;i<ans.size();i++)
            small = small*10 + ans[i];
      return small;
}
int main()
{
      ll a,b,s;
      cin >> a >> b >> s;
      memset(dp,-1,sizeof(dp));
      vector<int> d1,d2;
      d1 = digit(a-1);d2 = digit(b);
      ll s1 = digitSum(d1,0,1,0,s);
      memset(dp,-1,sizeof(dp));
      ll s2 = digitSum(d2,0,1,0,s);
      ll small = smallest(d1.size(),d2.size(),s,a,b);
      // cout << s1 << " " << s2 << endl;
      cout << s2 - s1 << endl;
      cout << small << endl;
}
