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

ll BS(Vi &a,ll x, int low,int high,int k){
    int ans = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int d = a[mid]-x;
        if(d<=k){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}

ll getSmall(Vi &a,ll mid){
    ll c = 0;
    for(int i=0;i<a.size();i++){
        int right = BS(a,a[i],i+1,a.size()-1,mid);
        if(right!=-1)
            c += right-i;
    }
    return c;
}
int main()
{
    fast;
    ll n,k;
    cin >> n >> k;
    Vi a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a.begin(),a.end());
    ll high = a[n-1] - a[0];
    ll low = a[n-1];
    for(int i=1;i<n;i++)
    {
        ll d = a[i]-a[i-1];
        low = min(low,d);
    }
    ll ans = -1;
    while(low<=high){
        ll mid = (low+high)/2;
        ll small = getSmall(a,mid);
        if(small<k)
            low = mid+1;
        else{
            ans = mid;
            high = mid-1;
        }
    }
    cout << ans << '\n';
}
