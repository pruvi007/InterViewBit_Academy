
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
int doUnion(int x,int y,int par[],int size[])
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
    }
    else
    {
        par[p1] = p2;
        size[p2] += s1;
    }
    return 1;
}
int main()
{
    fast;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    string s;
    cin >> s;
    int par[n+1], size[n+1];
    for(int i=0;i<=n;i++)
    {
        par[i] = i;
        size[i] = 1;
    }
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            int x = doUnion(i+1,i+2,par,size);
        }
    }
    bool possible = true;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=i+1)
        {
            if(find(a[i],i+1,par)==false )
            {
                possible = false;
                break;
            }
        }
    }
    if(possible)
        cout << "YES\n";
    else cout << "NO\n";
}