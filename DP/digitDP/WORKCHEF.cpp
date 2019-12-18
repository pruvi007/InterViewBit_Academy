#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define LCM 2520
// states denote (possible length of number, max sum poss, max diff digit poss, tight bound(bool))
ll dp[20][LCM][2][(1<<9) + 5];
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

ll digitDp(vector<int> digit,int K,int rem,int sum,int tight,int mask)
{
	if(rem==digit.size())
	{
	        int c = 0;
	        for(int i=1;i<=9;i++)
	        {
	        	// this means it conatins digit i
	        	if( (mask & 1<<(i-1)) >0 )
	        	{
	        		// this means it is divisible by i
	        		if(sum%i==0)
	        			c++;
	        	}
	        }
	        if(c>=K)
	        	return 1;
	        return 0;
	}
	if( dp[rem][sum][tight][mask]!=-1 )
        return dp[rem][sum][tight][mask];
	 
	int limit = (tight)?digit[rem]:9;
	ll ans = 0;
	for(int i=0;i<=limit;i++)
	{
	  		if(tight and digit[rem]<i)
	  			break;
	  		int newMask = mask;
	  		if(i!=0)
	  			newMask = mask | 1<<(i-1);
	        int curTight = (digit[rem]==i)?tight:0;
	        ans += digitDp( digit,K,rem+1,(sum*10+i)%LCM,curTight,newMask );
	}
	dp[rem][sum][tight][mask] = ans;
	return ans;
}
int main()
{
      int t;
      cin >> t;
      while(t--)
      {
            ll l,r,k;
            cin >> l >> r >> k;
            vector<int> d1,d2;
            d1 = digit(l-1);d2 = digit(r);
            memset(dp,-1,sizeof(dp));
            ll s1 = digitDp(d1,k,0,0,1,0);
            memset(dp,-1,sizeof(dp));
            ll s2 = digitDp(d2,k,0,0,1,0);
            // cout << s1 << " " << s2 << endl;
            cout << s2-s1 << endl;

      }
}
