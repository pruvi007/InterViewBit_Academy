// count subarrays with equal 1's and 0's.
// solution by @pruvi007

// app: replace 0 with -1. Hash the prefix sums with their frequencies. Now sum += freq*(freq-1)/2; because if
// sum[i] == sum[j] where i<j, then it means subarray from i+1 to j is 0 or contains same 1 and -1.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
      int t;
      cin>>t;
      while(t--)
      {
            int n;
            cin>>n;
            ll a[n];
            for(int i=0;i<n;i++)
            {
                  cin>>a[i];
                  if(a[i]==0)
                        a[i] = -1;
            }

            map<ll,ll> m;
            ll sum = 0;
            for(int i=0;i<n;i++)
            {
                  sum += a[i];
                  m[sum]++;
            }
            ll ans = 0;
            map<ll,ll>::iterator it;
            for(it=m.begin();it!=m.end();it++)
            {
                  ll d = it->second;
                  ans = ans + d*(d-1)/2;
            }
            if(m.find(0)!=m.end())
                  ans += m[0];
            cout<<ans<<endl;
      }
}
