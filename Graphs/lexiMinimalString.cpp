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
int doUnion(int x,int y,int par[],int size[], int m[])
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
        m[p1] = min( m[p1],m[p2] );
    }
    else
    {
        par[p1] = p2;
        size[p2] += s1;
        m[p2] = min( m[p1],m[p2] );
    }
    return 1;
}

int main()
{
    fast;
    string a,b,c;
    cin >> a >> b >> c;
    int par[26],size[26],m[26];
    for(int i=0;i<26;i++)
    {
        par[i] = i;
        size[i] = 1;
        m[i] = i;
    }
    for(int i=0;i<a.length();i++)
    {
        int x = a[i]%97;
        int y = b[i]%97;
        int pos = doUnion(x,y,par,size,m);
    }
    for(int i=0;i<c.length();i++)
    {
        char curCh = c[i];
        char minEquivalent = char(97+m[ getPar(c[i]%97,par) ]);
        char ans = min(curCh,minEquivalent);
        
        c[i] = ans;
    }
    cout << c << '\n';
}