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

ll M;
ll getPar(ll x,ll par[]){
    while(x!=par[x])
        x = par[x];
    return x;
}
ll find(ll x,ll y,ll par[])
{
    return getPar(x,par) == getPar(y,par);
}
ll doUnion(ll x,ll y,ll par[],ll size[],ll MP[],ll mp[],map<ll,ll> &val)
{
    if( find(x,y,par) )
        return -1;
    ll p1 = getPar(x,par);
    ll p2 = getPar(y,par);
    ll s1 = size[p1];
    ll s2 = size[p2];
    if( s1 > s2 )
    {
        par[p2] = p1;
        size[p1] += s2;
        MP[p1] = max(MP[p1],max((ll)x,(ll)y));
        mp[p1] = min(mp[p1],min((ll)x,(ll)y));
        ll v = MP[p1] - mp[p1];
        M = max(M,v);
    }
    else
    {
        par[p1] = p2;
        size[p2] += s1;
        MP[p2] = max(MP[p2],max((ll)x,(ll)y));
        mp[p2] = min(mp[p2],min((ll)x,(ll)y));
        ll v = MP[p2] - mp[p2];
        M = max(M,v);
    }
    return 1;
}

int main()
{
    //fast;
    ll n;
    cin >> n;
    map<ll, Vi> edge;
    for(int i=0;i<n-1;i++)
    {
        ll x,y;
        cin >> x >> y;
        edge[i+1].PB(x);
        edge[i+1].PB(y);
    }
    map<ll,ll> val;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        val[i+1] = x;
    }
        
    Vi order(n-1);
    for(int i=0;i<n-1;i++)
        cin >> order[i];
    // cout << order[0] << '\n';
    ll par[n+1],size[n+1];
    ll MP[n+1],mp[n+1];
    for(int i=1;i<=n;i++)
    {
        par[i] = i; 
        size[i] = 1;
        MP[i] = 0;
        mp[i]=INT_MAX;
    }
    Vi ans;
    M = 0;
    // cout << "Before DSU";
    for(int i=order.size()-1;i>=0;i--)
    {
        ll p = order[i];
        ans.PB(M);
        Vi e = edge[p];
        ll x = e[0], y = e[1];
        // cout << x << " " << y << '\n';
        ll poss = doUnion(x,y,par,size,MP,mp,val);
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout << ans[i] << '\n';
    
}