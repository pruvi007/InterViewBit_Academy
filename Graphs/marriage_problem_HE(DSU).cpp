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
	int n,m;
	cin >> n >> m;
	map<int,int> womenNum;
	for(int i=n+1;i<=n+m;i++)
		womenNum[i-n] = i;
	int par[n+m+1],size[n+m+1];
	for(int i=1;i<=n+m;i++)
	{
		par[i] = i;
		size[i] = 1;
	}
	int q1;
	cin >> q1;
	for(int i=0;i<q1;i++)
	{
		int x,y;
		cin >> x >> y;
		int p = doUnion(x,y,par,size);
	}
	int q2;
	cin >> q2;
	for(int i=0;i<q2;i++)
	{
		int x,y;
		cin >> x >> y;
		x = womenNum[x];y = womenNum[y];
		int p = doUnion(x,y,par,size);
	}
	int q3;
	cin >> q3;
	for(int i=0;i<q3;i++)
	{
		int x,y;
		cin >> x >> y;
		y = womenNum[y];
		int p = doUnion(x,y,par,size);
	}
	for(int i=1;i<=n+m;i++)
		cout << i << ": "<< par[i] << "\n";
	cout << endl;
	map<int,int> M,W;
	for(int i=1;i<=n;i++)
	{
		int p = getPar(i,par);
		M[p]++;
	}
	for(int i=n+1;i<=n+m;i++)
	{
		int p = getPar(i,par);
		W[p]++;
	}
	int TW = 0;
	for(auto it=W.begin();it!=W.end();it++)
		TW += it->second;
	ll ans = 0;
	for(auto it=M.begin();it!=M.end();it++)
	{
		int p = it->first;
		ans = ans + it->second * (TW-W[p]);
	}
	cout << ans << '\n';
}