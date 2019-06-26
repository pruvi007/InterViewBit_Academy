/*
	Count string of length N such that there are no consecutive 1's
	if x string end with 0 and y string end with 1
	then x will brach out to braches and y will brach out to 1 branch
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod = 1e9+7;
int Solution::solve(int A) {
    if(A==1)
        return 2;
    if(A==2)
        return 3;
    else
    {
        ll x = 2,y = 1;
        ll ans=3;
        for(int i=3;i<=A;i++)
        {
            ll t1 = (x%mod+y%mod)%mod;
            ll t2 = x%mod;
            ans = (t1%mod + t2%mod)%mod;
            x = (t1%mod);
            y = (t2%mod);
        }
        return ans%mod;
    }
    
}