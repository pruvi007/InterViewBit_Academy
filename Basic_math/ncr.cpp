/*
    Compute Ncr
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 2001
ll mod = 1e9+7;
ll f[100005];

ll power(ll a, ll b)
{
    ll res = 1;
    ll x = a;
    while(b)
    {
        if(b%2)
            res = (res%mod * x%mod)%mod;
        x = (x%mod*x%mod)%mod;
        b /= 2;
    }
    return res%mod;
}
ll ncr(ll a, ll b)
{
    ll num = f[a];
    ll den = ( f[a-b]%mod * f[b]%mod )%mod;
    
    // inverse modulo
    den = power(den,mod-2);
    
    return (num%mod * den%mod)%mod;
}
int main(){
    
    f[0] = 1;
    f[1] = 1;
    for(int i=2;i<=5000;i++)
        f[i] = (f[i-1]%mod * i%mod)%mod;
    
    ll ans[2002][2002]={0};
    for(int i=0;i<1799;i++)
    {
        for(int j=0;j<=i;j++)
            ans[i][j] = ncr(i,j)%mod;
    }
    int t;
    cin >> t;
    while(t--){
        ll n,r;
        cin >> n >> r;
        if(r > n)
            cout << 0 << endl;
        else
            cout << ans[n][r]%mod << endl;
    }
    
}