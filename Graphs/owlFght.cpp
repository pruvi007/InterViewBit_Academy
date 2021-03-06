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

int getPar(int x,int par[]){
    while(x!=par[x])
        x = par[x];
    return x;
}
int find(int x,int y,int par[])
{
    return getPar(x,par) == getPar(y,par);
}
int doUnion(int x,int y,int par[],int size[], int M[])
{
    if( find(x,y,par) )
        return -1;
    int p1 = getPar(x,par);
    int p2 = getPar(y,par);
    int s1 = size[p1];
    int s2 = size[p2];
    if( s1 > s2 )
    {
        par[p2] = p1;
        size[p1] += s2;
        M[p1] = max( M[p1], M[p2] );
    }
    else
    {
        par[p1] = p2;
        size[p2] += s1;
        M[p2] = max( M[p2], M[p1] );
    }
    return 1;
}

int main()
{
    fast;
    int n,m;
    cin >> n >> m;
    int par[n+1], size[n+1],M[n+1];
    for(int i=1;i<=n;i++)
    {
        par[i] = i;
        size[i] = 1;
        M[i] = i;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        int p = doUnion(x,y,par,size,M);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        int power1 = M[ getPar(x,par) ];
        int power2 = M[ getPar(y,par) ];
        if( power1>power2 )
            cout << x << '\n';
        else if( power1 < power2 )
            cout << y << '\n';
        else cout << "TIE\n";
    }
}