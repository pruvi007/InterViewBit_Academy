#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll MOD  = 1e9+7;
map<ll,ll> primeFactor(ll n){
    map<ll,ll> mp;
    while(n%2==0){
        mp[2]++;
        n/=2;
    }
    for(int i=3;i<=sqrt(n);i+=2)
    {
        while(n%i==0)
        {
            mp[i]++;
            n/=i;
        }
    }
    if(n>2)
        mp[n]++;
    return mp;
}
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> f,f1;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        map<ll,ll> m = primeFactor(a[i]);
        for(auto it=m.begin();it!=m.end();it++)
        {
            f[it->first] += it->second;
        }
    }
    f1=f;
    for(int i=0;i<n;i++)
    {
        map<ll,ll> m = primeFactor(a[i]);
        ll ans= 1;
        for(auto it=m.begin();it!=m.end();it++)
        {
            f1[it->first] -= it->second;
            if(f1[it->first]==0)
                f1.erase(it->first);
        }
        for(auto it=f1.begin();it!=f1.end();it++)
        {
            ans = (ans%MOD * (it->second+1)%MOD)%MOD;
        }
        f1 = f;
        cout << ans << " " ;
    }
    cout << endl;
}