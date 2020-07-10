/*
    handle - pruvi007
    questionName - 
    Contest - 
    Topic - 
    Platform - 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define fast         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF          1e18
#define MOD          1000000007
#define Vi           vector<ll> 
#define Vs           vector<string>
#define VI           vector<vector<ll> >
#define PII          pair<ll,ll> 
#define PSI          pair<string,ll>
#define PB           push_back


int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int DX[] = {0,-1,-1,-1,0,1,1,1};
int DY[] = {-1,-1,0,1,1,1,0,-1};

ll frog(Vi &h,int l)
{
    if(l>h.size()-1)
        return INT_MAX;
    if(l==h.size()-1)
        return 0;

    ll a = INT_MAX;
    ll b = INT_MAX;
    
    a = min(a,abs(h[l]-h[l+1]) + frog(h,l+1));
    a = min(a,abs(h[l]-h[l+2]) + frog(h,l+2));
    
    return a;

}
int main()
{
    fast;
    int n;
    cin >> n;
    Vi a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    int ans = frog(a,0);
    cout << ans << endl;
}