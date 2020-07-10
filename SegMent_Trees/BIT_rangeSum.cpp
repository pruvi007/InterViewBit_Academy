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


struct fenwickTree{
    Vi bit;
    int n;
    fenwickTree(int n){
        this->n = n+1;
    }
    void build(Vi &a){
        for(int i=0;i<=n;i++)
            bit.PB(0);
        for(int i=0;i<a.size();i++)
            add(i,a[i]);
    }
    ll sum(int idx){
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    void add(int idx, ll delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
    ll rangeQuery(int l,int r){
        return sum(r) - sum(l-1);
    }
    void show(){
        for(int i=0;i<bit.size();i++)
            cout << bit[i] << " ";
        cout << endl;
    }
};


int main()
{
    fast;
    int n;
    cin >> n;
    Vi a(n);
    
    for(int i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        a[i] = x;
    }
    fenwickTree *BIT = new fenwickTree(n);
    BIT->build(a);
    BIT->show();

    int q;
    cin >> q;
    while(q--){
        int ch;
        cin >> ch;
        if(ch==1){
            int ind,v;
            cin >> ind >> v;
            ll add = v - a[ind];
            a[ind] = v;
            BIT->add(ind,add);
        }
        else{
            int l,r ;
            cin >> l >> r;
            cout << BIT->rangeQuery(l,r) << endl;
        }
    }

}
